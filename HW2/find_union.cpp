#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define print(a) cout<<a<<endl;
using namespace std;

vector<unsigned int> find_union(vector<unsigned int> pos1,vector<unsigned int> pos2)
{
    vector<unsigned int> buffer;
    vector<unsigned int>::iterator it_i_2=pos2.begin();
    vector<unsigned int>::iterator end_of_it_i_2=pos2.end();
    for(vector<unsigned int>::iterator it_i=pos1.begin();it_i!=pos1.end();it_i++)
    {
            if(*it_i==*it_i_2)
            {
                buffer.push_back(*it_i);
                it_i_2++;
            }
            else if(*it_i_2<*it_i)
            {
                it_i_2++;
                it_i--;
            }
    }
    return buffer;
}
vector<unsigned int> find_possible_sentence(vector< vector<unsigned int> > combine_adress)
{
    vector<unsigned int> buffer(combine_adress[0]);
    if(combine_adress.size()>1)
    {
        for(vector< vector<unsigned int> >::iterator it_i=combine_adress.begin()+1;it_i!=combine_adress.end();it_i++)
        {
            buffer=find_union(buffer,*it_i);
        }
    }
    return buffer;
}


int main()
{
    vector<unsigned int> pos1 {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 6287, 89909, 147347, 187905, 232916, 237768, 260341, 282608, 304886, 476372, 528610, 582853, 602407, 724417, 725902, 763056, 772510, 795656, 830193, 1042996, 1057321, 1062434, 1206291, 1261564, 1313409, 1580477, 1698160, 1701025, 2072903, 2226292, 2601066, 2635145, 2671752, 2771245, 2887860, 3019576, 3044406, 3091608, 3182222, 3225254, 3238899, 3253153, 3325161, 3342666, 3482678, 3491433, 3491461, 3536065, 3590774, 3713038, 3716227, 3760351, 3799166, 3832841, 3848006, 3905551, 3935314, 4120662, 4270102, 4301162, 4404188, 4605856, 4697173, 4731956, 4797493, 4802576, 4802712, 4838810, 4919403, 4989917, 4995587, 5030523, 5057625, 5071720, 5077115, 5089634, 5117321, 5221173, 5242121, 5815685, 5823054, 5857212, 5872627, 5903240, 5996575, 6280389, 6423103, 6455265, 6514110, 6921192, 7038912, 7148995, 7250134, 7260035, 7287934, 7393917, 7402055, 7414875, 7453660, 7501069, 7552047, 7734084, 7746859, 7776336, 7850974, 7877159, 7882892, 7889941, 7899691, 7901836, 8048161, 8059454, 8126390, 8130877, 8147732, 8156354, 8164491, 8251590, 8252032, 8287238, 8289263, 8355506, 8385337};
    vector<unsigned int> pos2 {1, 169, 170, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 273, 324, 853, 31244, 161917, 304887, 582854, 593799, 593913, 594362, 598912, 621310, 720955, 1062435, 1099263, 1104684, 1206461, 1206509, 1238923, 1239057, 1332467, 1345957, 1732643, 1833644, 1854918, 2771246, 2955733, 2955966, 2956334, 2981770, 2989859, 2989884, 2990101, 3030698, 3030706, 3030746, 3031594, 3162297, 3162385, 3162602, 3713039, 4192325, 4540470, 4545964, 4797494, 4802713, 4919404, 5030524, 5117322, 5479039, 5903241, 5915206, 6471231, 6578984, 6975081, 7172548, 7248408, 7287935, 7552048, 7692031, 7715508, 7734131, 7734141, 7734199, 7734277, 8035134, 8252033};
    vector< vector<unsigned int> > combine_adress;
    combine_adress.push_back(pos1);
    combine_adress.push_back(pos2);



    vector<unsigned int> result;
    result=find_possible_sentence(combine_adress);
    for(vector<unsigned int>::iterator it_i=result.begin();it_i!=result.end();it_i++)
    {
        cout<<*it_i<<' ';
    }
    return 0;
}
