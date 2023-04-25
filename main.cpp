#include <iostream> // std::cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <cstdint>
#include <bitset>
#include <cstdlib>

using namespace std;

class PGM_Image {
public:
    std::string name;
    int numrows;
    int numcols;
    int max_px_val;
    uint8_t *data;

    PGM_Image(std::string name);

    void save(std::string name);
};

PGM_Image::PGM_Image(std::string name) : name(name), numrows(0), numcols(0), max_px_val(0), data(nullptr)
{
    std::ifstream infile(this->name);
    std::stringstream ss;
    std::string inputLine = "";

    if (!infile) {
        std::cerr << "Failed to open image " << this->name;
        std::exit(EXIT_FAILURE);
    }

    // First line : version
    std::getline(infile, inputLine);
    //std::cout << "Version: " << inputLine << std::endl;

    // Second line: numcols numrows
    std::getline(infile, inputLine);
    ss << inputLine;
    ss >> this->numcols >> this->numrows;
    //std::cout << this->numcols << " columns and " << this->numrows << " rows" << std::endl;

    // Third line: max pixel value
    std::getline(infile, inputLine);
    ss = std::stringstream();

    ss << inputLine;
    ss >> this->max_px_val;
    //std::cout << "Px val is " << this->max_px_val << std::endl;

    std::filebuf *pbuf = infile.rdbuf();
    //std::streamsize curr = pbuf->pubseekoff(0, infile.cur);
    //std::streamsize size = pbuf->pubseekoff(0, infile.end);
    //pbuf->pubseekoff(curr, infile.beg);

    //std::cout << "Curr is " << curr << "\n";
    //std::cout << "Size is " << size - curr << "\n";
    //std::cout << "Size is " << this->numrows * this->numcols << "\n";

    this->data = new uint8_t[this->numrows * this->numcols];
    pbuf->sgetn(reinterpret_cast<char*>(this->data), this->numrows * this->numcols);

    infile.close();
}

void PGM_Image::save(std::string name) {
    std::ofstream outfile(name);
    if (!outfile) {
        std::cerr << "Failed to open image " << this->name;
        std::exit(EXIT_FAILURE);
    }

    // Version P5 means that the PGM data is in binary form
    outfile << "P5" << std::endl;
    outfile << this->numcols << " " << this->numrows << std::endl;
    outfile << this->max_px_val << std::endl;
    std::streambuf *pbuf = outfile.rdbuf();
    pbuf->sputn(reinterpret_cast<char *>(this->data), this->numcols * this->numrows);
    outfile.close();
}

class SteganoDecoder {
public:
    static std::string lsb_decode_message(PGM_Image &img);
};


std::string SteganoDecoder::lsb_decode_message(PGM_Image &img) {
    int current = 0;
    int currentIndex = 0;

    char last[4];

    string str = "";

    for (int i = 0;; i++) {
        int lastBits = img.data[i] % 4;
        current = current << 2;
        current += lastBits;
        currentIndex++;
        if (currentIndex == 4) {
            char chr = (char) current;
            last[0]=last[1];
            last[1]=last[2];
            last[2]=last[3];
            last[3]=chr;
            str+=chr;
            currentIndex = 0;
            current = 0;
        }
        if(
                last[0]=='L'&&
                last[1]=='S'&&
                last[2]=='S'&&
                last[3]=='L'
                ){
            break;
        }

    }

    return str;
}

int main() {
    PGM_Image img1("../lyutsifer-ig.pgm");
    PGM_Image img2("../lyutsifer-original.pgm");

    //SteganoDecoder::lsb_decode_message(img2);
    //cout<<endl;
    //SteganoDecoder::lsb_decode_message(img);


    //for (int i = 0; i < 100000; i++) {
    //    cout<<(int)img1.data[i]<<" vs "<<(int)img2.data[i]<<endl;
    //    if(img1.data[i]!=img2.data[i]){
    //        cout<<i<<endl;
    //        break;
    //    }
    //    //cout<<(int)img.data[i]<<" ";
    //}=last[1
    //cout<<"Here";

    auto msg = SteganoDecoder::lsb_decode_message(img1);
    std::cout << msg << "\n";

    // meld <(hexdump -C lyutsifer-ig.pgm) <(hexdump -C lyutsifer-original.pgm)
}