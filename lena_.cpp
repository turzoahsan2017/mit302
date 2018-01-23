#include <iostream>
#include <fstream>

using namespace std;

ifstream ifs;
ofstream ofs, ofsbw;

struct pix
{
    char r;
    char g;
    char b;
} px;

struct blackwhite
{
    char l1;
    char l2;
    char l3;
} bw;


char Header[54];

char lena_ip[]      =   "d:\\lena.bmp";
char lena_op[]      =   "d:\\lena2.bmp";
char lena_bw[]      =   "d:\\lena3.bmp";

int main()
{

    ifs.open( lena_ip, ios::in|ios::binary );
    ofs.open( lena_op, ios::out|ios::binary );
    ofsbw.open( lena_bw, ios::out|ios::binary );

    ifs.read( (char*) (&Header),sizeof(Header) );
    ofs.write( (char*) (&Header),sizeof(Header) );
    ofsbw.write( (char*) (&Header),sizeof(Header) );

    while(!ifs.eof())
    {
        ifs.read( (char*) (&px),sizeof(px) );
        ofs.write( (char*) (&px),sizeof(px) );

        int lum = (int)( (.21*px.r) + (.72*px.g) + (.07*px.b) );

        bw.l1 = bw.l2 = bw.l3 = lum;

        ofsbw.write( (char*) (&bw),sizeof(bw) );
    }

    ifs.close();
    ofs.close();
    ofsbw.close();

    return 0;
}
