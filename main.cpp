/*
	Acadnet 2017 - Etapa Judeteana
	Problema B
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define N 100
#define MAXLEN 50

#define MIN_GRADE 1
#define MAX_GRADE 10

struct {
    int values[N];
    int next_index;
} grades;

struct {
    int grade_distribution[MAX_GRADE - MIN_GRADE + 2];
    double average;
    double mean_squared_error;
} stats;

void read_input() {
    FILE *fin = fopen("../input.txt", "r");
    if (fin == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        exit(-1);
    }

    char first_name[MAXLEN], last_name[MAXLEN], email[MAXLEN], phone[MAXLEN], grade[MAXLEN];
    int grade_value;

    while (fscanf(fin, "%s%s%s%s%s", first_name, last_name, email, phone, grade) != EOF) {
        grade_value = atoi(grade);
        grades.values[grades.next_index++] = grade_value;
    }
    fclose(fin);
}

void compute_average() {
    double sum = 0;
    int i;

    for (i = 1; i < grades.next_index; i++)
        sum += grades.values[i];

    stats.average = sum / (grades.next_index -1);
}

void compute_mean_squared_error() {
    int i;
    double sum = 0;

    for (i = 1; i < grades.next_index; i++) {
        double dif = grades.values[i] - stats.average;
        sum += dif * dif;
    }
    stats.mean_squared_error = sqrt((double) sum / (grades.next_index - 2));

}

void compute_grade_distribution() {
    int i;

    for (i = 1; i < grades.next_index; i++)
        stats.grade_distribution[grades.values[i]]++;
}

void compute_statistics() {
    compute_average();
    compute_mean_squared_error();
    compute_grade_distribution();
}

void write_output() {
    int i;
    FILE *fout = fopen("../output.txt", "w");
    if (fout == NULL) {
        fprintf(stderr, "Failed to open output file.\n");
        exit(-1);
    }

    fprintf(fout, "%lf %lf\n", stats.average, stats.mean_squared_error);
    for (i = MIN_GRADE; i <= MAX_GRADE; i++)
        fprintf(fout, "%d ", stats.grade_distribution[i]);
    fclose(fout);
}

int main() {
    int ret = 0;

    read_input();
    compute_statistics();
    write_output();

    return ret;
}
