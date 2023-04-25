#include <stdio.h>
#include <math.h>

unsigned int get_leftmost_nbits(unsigned int packet, unsigned int n)
{
    return packet >> 31 - n + 1;
}

unsigned int parse_n_of_bits(unsigned int* packet, int n_of_bits)
{
    unsigned int ret = get_leftmost_nbits(*packet, n_of_bits);
    *packet <<= n_of_bits;
    return ret;
}

char get_op(unsigned int op)
{
    switch(op)
    {
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        default: return '/';
    }
}

void input_data_to_operands(unsigned short* input_data, unsigned int len, unsigned int* operands, int dim, unsigned int n_ops)
{
    unsigned int element;
    for(int i = 0; i < len; i++)
    {
        element = input_data[i] << 16;

		int operands_in_input = sizeof(input_data[0]) * 8 / dim;
        for(int j = 0; j < operands_in_input && (j + i * operands_in_input) < n_ops ; j++)
        {
            //printf("HERE\n");
            operands[operands_in_input * i + j] = parse_n_of_bits(&element, dim);
        }

    }
}

int compute_result(unsigned int* op, unsigned int* operands, unsigned int dim)
{
    int result = operands[0];
    for(int i = 0; i < dim; i++)
    {
        //printf("result = %d\n", result);
        if (op[i] == 0)
            result += operands[i + 1];
        else if (op[i] == 1)
            result -= operands[i + 1];
        else if (op[i] == 2)
            result *= operands[i + 1];
        else if (op[i] == 3)
            result /= operands[i + 1];
    }
    return result;
}

int main()
{
    unsigned int packet;
    scanf("%u", &packet);
    unsigned int n_ops = parse_n_of_bits(&packet, 3);
    ++n_ops;
    //printf("n_ops = %i\n", n_ops);

    //get instructions
    unsigned int op[10];
    for(int i = 0; i < n_ops; i++)
    {
        op[i] = parse_n_of_bits(&packet, 2);
    }
    //printf("op = ");
    //for(int i = 0; i < n_ops; i++){
    //    printf("%i ", op[i]);
    //}
    //printf("\n");

    //return 0;

    //get dim
    unsigned int dim = parse_n_of_bits(&packet, 4);
    ++dim;

    //printf("dim = %i\n", dim);

    //get input data
    int n_of_input_data = ceil(((n_ops + 1) * dim) / 16.0);

    //printf("n_of_input_data = %i\n", n_of_input_data);

    unsigned short input_data[10];
    for(int i = 0; i < n_of_input_data; i++)
    {
        scanf("%hu", &input_data[i]);
    }

    //printf("input_data = ");
    //for(int i = 0; i < n_of_input_data; i++){
    //    printf("%i ", input_data[i]);
    //}
    //printf("\n");

    unsigned int operands[10];
    input_data_to_operands(input_data, n_of_input_data, operands, dim, n_ops+1);

    //printf("operands = ");
    //for(int i = 0; i < 10; i++){
    //    printf("%i ", operands[i]);
    //}
    //printf("\n");


    printf("%d\n", compute_result(op, operands, n_ops));
}