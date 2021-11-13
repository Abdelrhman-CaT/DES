#include <iostream>
#include <map>

using namespace std;


// convert hexadecimal to binary
string hexaToBinary(string hex) {
    map<char, string> hexadecimalToBinary;
    hexadecimalToBinary['0'] = "0000";
    hexadecimalToBinary['1'] = "0001";
    hexadecimalToBinary['2'] = "0010";
    hexadecimalToBinary['3'] = "0011";
    hexadecimalToBinary['4'] = "0100";
    hexadecimalToBinary['5'] = "0101";
    hexadecimalToBinary['6'] = "0110";
    hexadecimalToBinary['7'] = "0111";
    hexadecimalToBinary['8'] = "1000";
    hexadecimalToBinary['9'] = "1001";
    hexadecimalToBinary['A'] = "1010";
    hexadecimalToBinary['B'] = "1011";
    hexadecimalToBinary['C'] = "1100";
    hexadecimalToBinary['D'] = "1101";
    hexadecimalToBinary['E'] = "1110";
    hexadecimalToBinary['F'] = "1111";

    string retVal = "";

    for (int i = 0; i < hex.length(); i++) {
        retVal += hexadecimalToBinary[hex[i]];
    }

    return retVal;
}

// convert binary to hexadecimal 
string binaryToHexa(string bin) {
    map<string, string> BinaryToHexadecimal;

    BinaryToHexadecimal["0000"] = "0";
    BinaryToHexadecimal["0001"] = "1";
    BinaryToHexadecimal["0010"] = "2";
    BinaryToHexadecimal["0011"] = "3";
    BinaryToHexadecimal["0100"] = "4";
    BinaryToHexadecimal["0101"] = "5";
    BinaryToHexadecimal["0110"] = "6";
    BinaryToHexadecimal["0111"] = "7";
    BinaryToHexadecimal["1000"] = "8";
    BinaryToHexadecimal["1001"] = "9";
    BinaryToHexadecimal["1010"] = "A";
    BinaryToHexadecimal["1011"] = "B";
    BinaryToHexadecimal["1100"] = "C";
    BinaryToHexadecimal["1101"] = "D";
    BinaryToHexadecimal["1110"] = "E";
    BinaryToHexadecimal["1111"] = "F";

    string retVal = "";

    for (int i = 0; i < bin.length(); i+=4) {
        string temp = "";
        for (int j = i; j < i+4; j++) {
            temp += bin[j];
        }
        retVal += BinaryToHexadecimal[temp];
    }

    return retVal;
}

// left circular shift for key Takes Binary 28 bit and Returns Binary 28 bit
string leftCircularShift(string bin, int shift) {
    string retVal = "";
    string shiftedBits = "";
    for (int i = 0; i < shift; i++) {
        shiftedBits += bin[i];
    }
    for (int i = shift; i < bin.length(); i++) {
        retVal += bin[i];
    }
    retVal += shiftedBits;
    return retVal;
}

// permutation choice 1 (key)  Takes Binary 64 bit and Returns Binary 56 bit
string permutedChoice1(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 57;
    permuated[1] = 49;
    permuated[2] = 41;
    permuated[3] = 33;
    permuated[4] = 25;
    permuated[5] = 17;
    permuated[6] = 9;
    permuated[7] = 1;
    permuated[8] = 58;
    permuated[9] = 50;
    permuated[10] = 42;
    permuated[11] = 34;
    permuated[12] = 26;
    permuated[13] = 18;
    permuated[14] = 10;
    permuated[15] = 2;
    permuated[16] = 59;
    permuated[17] = 51;
    permuated[18] = 43;
    permuated[19] = 35;
    permuated[20] = 27;
    permuated[21] = 19;
    permuated[22] = 11;
    permuated[23] = 3;
    permuated[24] = 60;
    permuated[25] = 52;
    permuated[26] = 44;
    permuated[27] = 36;
    permuated[28] = 63;
    permuated[29] = 55;
    permuated[30] = 47;
    permuated[31] = 39;
    permuated[32] = 31;
    permuated[33] = 23;
    permuated[34] = 15;
    permuated[35] = 7;
    permuated[36] = 62;
    permuated[37] = 54;
    permuated[38] = 46;
    permuated[39] = 38;
    permuated[40] = 30;
    permuated[41] = 22;
    permuated[42] = 14;
    permuated[43] = 6;
    permuated[44] = 61;
    permuated[45] = 53;
    permuated[46] = 45;
    permuated[47] = 37;
    permuated[48] = 29;
    permuated[49] = 21;
    permuated[50] = 13;
    permuated[51] = 5;
    permuated[52] = 28;
    permuated[53] = 20;
    permuated[54] = 12;
    permuated[55] = 4;

    for (int i = 0; i < 56; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// permutation choice 2 (key)  Takes Binary 56 bit and Returns Binary 48 bit
string permutedChoice2(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 14;
    permuated[1] = 17;
    permuated[2] = 11;
    permuated[3] = 24;
    permuated[4] = 1;
    permuated[5] = 5;
    permuated[6] = 3;
    permuated[7] = 28;
    permuated[8] = 15;
    permuated[9] = 6;
    permuated[10] = 21;
    permuated[11] = 10;
    permuated[12] = 23;
    permuated[13] = 19;
    permuated[14] = 12;
    permuated[15] = 4;
    permuated[16] = 26;
    permuated[17] = 8;
    permuated[18] = 16;
    permuated[19] = 7;
    permuated[20] = 27;
    permuated[21] = 20;
    permuated[22] = 13;
    permuated[23] = 2;
    permuated[24] = 41;
    permuated[25] = 52;
    permuated[26] = 31;
    permuated[27] = 37;
    permuated[28] = 47;
    permuated[29] = 55;
    permuated[30] = 30;
    permuated[31] = 40;
    permuated[32] = 51;
    permuated[33] = 45;
    permuated[34] = 33;
    permuated[35] = 48;
    permuated[36] = 44;
    permuated[37] = 49;
    permuated[38] = 39;
    permuated[39] = 56;
    permuated[40] = 34;
    permuated[41] = 53;
    permuated[42] = 46;
    permuated[43] = 42;
    permuated[44] = 50;
    permuated[45] = 36;
    permuated[46] = 29;
    permuated[47] = 32;

    for (int i = 0; i < 48; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// swap the first 32 bits with the last 32 bits (Data after round 16) Takes Binary 64 bit and Returns Binary 64 bit
string swap32bit(string bin) {
    string retVal = "";
    string first = "";
    string last = "";

    for (int i = 0; i < bin.length() / 2; i++) {
        first += bin[i];
    }
    for (int i = bin.length() / 2; i < bin.length(); i++) {
        last += bin[i];
    }
    retVal = last + first;
    return retVal;
}

// initial permutation (data)  Takes Binary 64 bit and Returns Binary 64 bit
string initialPermutation(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 58;
    permuated[1] = 50;
    permuated[2] = 42;
    permuated[3] = 34;
    permuated[4] = 26;
    permuated[5] = 18;
    permuated[6] = 10;
    permuated[7] = 2;
    permuated[8] = 60;
    permuated[9] = 52;
    permuated[10] = 44;
    permuated[11] = 36;
    permuated[12] = 28;
    permuated[13] = 20;
    permuated[14] = 12;
    permuated[15] = 4;
    permuated[16] = 62;
    permuated[17] = 54;
    permuated[18] = 46;
    permuated[19] = 38;
    permuated[20] = 30;
    permuated[21] = 22;
    permuated[22] = 14;
    permuated[23] = 6;
    permuated[24] = 64;
    permuated[25] = 56;
    permuated[26] = 48;
    permuated[27] = 40;
    permuated[28] = 32;
    permuated[29] = 24;
    permuated[30] = 16;
    permuated[31] = 8;
    permuated[32] = 57;
    permuated[33] = 49;
    permuated[34] = 41;
    permuated[35] = 33;
    permuated[36] = 25;
    permuated[37] = 17;
    permuated[38] = 9;
    permuated[39] = 1;
    permuated[40] = 59;
    permuated[41] = 51;
    permuated[42] = 43;
    permuated[43] = 35;
    permuated[44] = 27;
    permuated[45] = 19;
    permuated[46] = 11;
    permuated[47] = 3;
    permuated[48] = 61;
    permuated[49] = 53;
    permuated[50] = 45;
    permuated[51] = 37;
    permuated[52] = 29;
    permuated[53] = 21;
    permuated[54] = 13;
    permuated[55] = 5;
    permuated[56] = 63;
    permuated[57] = 55;
    permuated[58] = 47;
    permuated[59] = 39;
    permuated[60] = 31;
    permuated[61] = 23;
    permuated[62] = 15;
    permuated[63] = 7;

    for (int i = 0; i < 64; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// inverse initial permutation (data)  Takes Binary 64 bit and Returns Binary 64 bit
string inverseInitialPermutation(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 40;
    permuated[1] = 8;
    permuated[2] = 48;
    permuated[3] = 16;
    permuated[4] = 56;
    permuated[5] = 24;
    permuated[6] = 64;
    permuated[7] = 32;
    permuated[8] = 39;
    permuated[9] = 7;
    permuated[10] = 47;
    permuated[11] = 15;
    permuated[12] = 55;
    permuated[13] = 23;
    permuated[14] = 63;
    permuated[15] = 31;
    permuated[16] = 38;
    permuated[17] = 6;
    permuated[18] = 46;
    permuated[19] = 14;
    permuated[20] = 54;
    permuated[21] = 22;
    permuated[22] = 62;
    permuated[23] = 30;
    permuated[24] = 37;
    permuated[25] = 5;
    permuated[26] = 45;
    permuated[27] = 13;
    permuated[28] = 53;
    permuated[29] = 21;
    permuated[30] = 61;
    permuated[31] = 29;
    permuated[32] = 36;
    permuated[33] = 4;
    permuated[34] = 44;
    permuated[35] = 12;
    permuated[36] = 52;
    permuated[37] = 20;
    permuated[38] = 60;
    permuated[39] = 28;
    permuated[40] = 35;
    permuated[41] = 3;
    permuated[42] = 43;
    permuated[43] = 11;
    permuated[44] = 51;
    permuated[45] = 19;
    permuated[46] = 59;
    permuated[47] = 27;
    permuated[48] = 34;
    permuated[49] = 2;
    permuated[50] = 42;
    permuated[51] = 10;
    permuated[52] = 50;
    permuated[53] = 18;
    permuated[54] = 58;
    permuated[55] = 26;
    permuated[56] = 33;
    permuated[57] = 1;
    permuated[58] = 41;
    permuated[59] = 9;
    permuated[60] = 49;
    permuated[61] = 17;
    permuated[62] = 57;
    permuated[63] = 25;

    for (int i = 0; i < 64; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// expansion permutation  Takes Binary 32 bit and Returns Binary 48 bit
string expansionPermutation(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 32;
    permuated[1] = 1;
    permuated[2] = 2;
    permuated[3] = 3;
    permuated[4] = 4;
    permuated[5] = 5;
    permuated[6] = 4;
    permuated[7] = 5;
    permuated[8] = 6;
    permuated[9] = 7;
    permuated[10] = 8;
    permuated[11] = 9;
    permuated[12] = 8;
    permuated[13] = 9;
    permuated[14] = 10;
    permuated[15] = 11;
    permuated[16] = 12;
    permuated[17] = 13;
    permuated[18] = 12;
    permuated[19] = 13;
    permuated[20] = 14;
    permuated[21] = 15;
    permuated[22] = 16;
    permuated[23] = 17;
    permuated[24] = 16;
    permuated[25] = 17;
    permuated[26] = 18;
    permuated[27] = 19;
    permuated[28] = 20;
    permuated[29] = 21;
    permuated[30] = 20;
    permuated[31] = 21;
    permuated[32] = 22;
    permuated[33] = 23;
    permuated[34] = 24;
    permuated[35] = 25;
    permuated[36] = 24;
    permuated[37] = 25;
    permuated[38] = 26;
    permuated[39] = 27;
    permuated[40] = 28;
    permuated[41] = 29;
    permuated[42] = 28;
    permuated[43] = 29;
    permuated[44] = 30;
    permuated[45] = 31;
    permuated[46] = 32;
    permuated[47] = 1;

    for (int i = 0; i < 48; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// xor Takes 2 Binary 48 bit and Returns Binary 48 bit
string xorS(string data, string key) {
    string retVal = "";
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == key[i]) {
            retVal += "0";
        }
        else {
            retVal += "1";
        }
    }
    return retVal;
}

// permutation  Takes Binary 32 bit and Returns Binary 32 bit
string permutation(string bin) {
    map<int, int> permuated;
    string retVal = "";

    permuated[0] = 16;
    permuated[1] = 7;
    permuated[2] = 20;
    permuated[3] = 21;
    permuated[4] = 29;
    permuated[5] = 12;
    permuated[6] = 28;
    permuated[7] = 17;
    permuated[8] = 1;
    permuated[9] = 15;
    permuated[10] = 23;
    permuated[11] = 26;
    permuated[12] = 5;
    permuated[13] = 18;
    permuated[14] = 31;
    permuated[15] = 10;
    permuated[16] = 2;
    permuated[17] = 8;
    permuated[18] = 24;
    permuated[19] = 14;
    permuated[20] = 32;
    permuated[21] = 27;
    permuated[22] = 3;
    permuated[23] = 9;
    permuated[24] = 19;
    permuated[25] = 13;
    permuated[26] = 30;
    permuated[27] = 6;
    permuated[28] = 22;
    permuated[29] = 11;
    permuated[30] = 4;
    permuated[31] = 25;

    for (int i = 0; i < 32; i++) {
        retVal += bin[permuated[i] - 1];
    }

    return retVal;
}

// convert decimal up to 15 to binary
string decimalToBinary(string dec) {
    string retVal = "";
    if (dec == "0") {
        retVal = "0000";
    }
    else if (dec == "1") {
        retVal = "0001";
    }
    else if (dec == "2") {
        retVal = "0010";
    }
    else if (dec == "3") {
        retVal = "0011";
    }
    else if (dec == "4") {
        retVal = "0100";
    }
    else if (dec == "5") {
        retVal = "0101";
    }
    else if (dec == "6") {
        retVal = "0110";
    }
    else if (dec == "7") {
        retVal = "0111";
    }
    else if (dec == "8") {
        retVal = "1000";
    }
    else if (dec == "9") {
        retVal = "1001";
    }
    else if (dec == "10") {
        retVal = "1010";
    }
    else if (dec == "11") {
        retVal = "1011";
    }
    else if (dec == "12") {
        retVal = "1100";
    }
    else if (dec == "13") {
        retVal = "1101";
    }
    else if (dec == "14") {
        retVal = "1110";
    }
    else if (dec == "15") {
        retVal = "1111";
    }
    return retVal;
}

// S-Box Takes Binary 48 bit and Returns Binary 32 bit
string sbox(string bin) {
    string retVal = "";
    map<string, string> sub1;
    map<string, string> sub2;
    map<string, string> sub3;
    map<string, string> sub4;
    map<string, string> sub5;
    map<string, string> sub6;
    map<string, string> sub7;
    map<string, string> sub8;

    sub1["000000"] = "14"; 
    sub1["000001"] = "4"; 
    sub1["000010"] = "13"; 
    sub1["000011"] = "1"; 
    sub1["000100"] = "2"; 
    sub1["000101"] = "15"; 
    sub1["000110"] = "11"; 
    sub1["000111"] = "8"; 
    sub1["001000"] = "3"; 
    sub1["001001"] = "10"; 
    sub1["001010"] = "6"; 
    sub1["001011"] = "12"; 
    sub1["001100"] = "5"; 
    sub1["001101"] = "9"; 
    sub1["001110"] = "0"; 
    sub1["001111"] = "7"; 

    sub1["010000"] = "0"; 
    sub1["010001"] = "15"; 
    sub1["010010"] = "7"; 
    sub1["010011"] = "4"; 
    sub1["010100"] = "14"; 
    sub1["010101"] = "2"; 
    sub1["010110"] = "13"; 
    sub1["010111"] = "1";
    sub1["011000"] = "10"; 
    sub1["011001"] = "6"; 
    sub1["011010"] = "12"; 
    sub1["011011"] = "11";
    sub1["011100"] = "9"; 
    sub1["011101"] = "5"; 
    sub1["011110"] = "3"; 
    sub1["011111"] = "8"; 

    sub1["100000"] = "4"; 
    sub1["100001"] = "1"; 
    sub1["100010"] = "14"; 
    sub1["100011"] = "8";
    sub1["100100"] = "13"; 
    sub1["100101"] = "6"; 
    sub1["100110"] = "2"; 
    sub1["100111"] = "11"; 
    sub1["101000"] = "15"; 
    sub1["101001"] = "12"; 
    sub1["101010"] = "9"; 
    sub1["101011"] = "7"; 
    sub1["101100"] = "3"; 
    sub1["101101"] = "10"; 
    sub1["101110"] = "5"; 
    sub1["101111"] = "0"; 

    sub1["110000"] = "15"; 
    sub1["110001"] = "12";
    sub1["110010"] = "8"; 
    sub1["110011"] = "2"; 
    sub1["110100"] = "4"; 
    sub1["110101"] = "9"; 
    sub1["110110"] = "1"; 
    sub1["110111"] = "7"; 
    sub1["111000"] = "5";
    sub1["111001"] = "11";
    sub1["111010"] = "3"; 
    sub1["111011"] = "14"; 
    sub1["111100"] = "10"; 
    sub1["111101"] = "0"; 
    sub1["111110"] = "6"; 
    sub1["111111"] = "13";

    // ------------------------------------------------

    sub2["000000"] = "15"; 
    sub2["000001"] = "1"; 
    sub2["000010"] = "8"; 
    sub2["000011"] = "14"; 
    sub2["000100"] = "6"; 
    sub2["000101"] = "11"; 
    sub2["000110"] = "3"; 
    sub2["000111"] = "4"; 
    sub2["001000"] = "9"; 
    sub2["001001"] = "7"; 
    sub2["001010"] = "2"; 
    sub2["001011"] = "13"; 
    sub2["001100"] = "12"; 
    sub2["001101"] = "0"; 
    sub2["001110"] = "5"; 
    sub2["001111"] = "10"; 

    sub2["010000"] = "3"; 
    sub2["010001"] = "13"; 
    sub2["010010"] = "4"; 
    sub2["010011"] = "7"; 
    sub2["010100"] = "15"; 
    sub2["010101"] = "2"; 
    sub2["010110"] = "8"; 
    sub2["010111"] = "14"; 
    sub2["011000"] = "12"; 
    sub2["011001"] = "0"; 
    sub2["011010"] = "1"; 
    sub2["011011"] = "10"; 
    sub2["011100"] = "6"; 
    sub2["011101"] = "9"; 
    sub2["011110"] = "11"; 
    sub2["011111"] = "5"; 

    sub2["100000"] = "0"; 
    sub2["100001"] = "14"; 
    sub2["100010"] = "7"; 
    sub2["100011"] = "11"; 
    sub2["100100"] = "10"; 
    sub2["100101"] = "4"; 
    sub2["100110"] = "13"; 
    sub2["100111"] = "1"; 
    sub2["101000"] = "5"; 
    sub2["101001"] = "8"; 
    sub2["101010"] = "12"; 
    sub2["101011"] = "6"; 
    sub2["101100"] = "9"; 
    sub2["101101"] = "3"; 
    sub2["101110"] = "2"; 
    sub2["101111"] = "15"; 

    sub2["110000"] = "13"; 
    sub2["110001"] = "8"; 
    sub2["110010"] = "10"; 
    sub2["110011"] = "1"; 
    sub2["110100"] = "3"; 
    sub2["110101"] = "15"; 
    sub2["110110"] = "4"; 
    sub2["110111"] = "2"; 
    sub2["111000"] = "11"; 
    sub2["111001"] = "6"; 
    sub2["111010"] = "7"; 
    sub2["111011"] = "12"; 
    sub2["111100"] = "0"; 
    sub2["111101"] = "5"; 
    sub2["111110"] = "14"; 
    sub2["111111"] = "9"; 

    //-----------------------------------------------

    sub3["000000"] = "10";
    sub3["000001"] = "0";
    sub3["000010"] = "9";
    sub3["000011"] = "14";
    sub3["000100"] = "6";
    sub3["000101"] = "3";
    sub3["000110"] = "15";
    sub3["000111"] = "5";
    sub3["001000"] = "1";
    sub3["001001"] = "13";
    sub3["001010"] = "12";
    sub3["001011"] = "7";
    sub3["001100"] = "11";
    sub3["001101"] = "4";
    sub3["001110"] = "2";
    sub3["001111"] = "8";

    sub3["010000"] = "13";
    sub3["010001"] = "7";
    sub3["010010"] = "0";
    sub3["010011"] = "9";
    sub3["010100"] = "3";
    sub3["010101"] = "4";
    sub3["010110"] = "6";
    sub3["010111"] = "10";
    sub3["011000"] = "2";
    sub3["011001"] = "8";
    sub3["011010"] = "5";
    sub3["011011"] = "14";
    sub3["011100"] = "12";
    sub3["011101"] = "11";
    sub3["011110"] = "15";
    sub3["011111"] = "1";

    sub3["100000"] = "13";
    sub3["100001"] = "6";
    sub3["100010"] = "4";
    sub3["100011"] = "9";
    sub3["100100"] = "8";
    sub3["100101"] = "15";
    sub3["100110"] = "3";
    sub3["100111"] = "0";
    sub3["101000"] = "11";
    sub3["101001"] = "1";
    sub3["101010"] = "2";
    sub3["101011"] = "12";
    sub3["101100"] = "5";
    sub3["101101"] = "10";
    sub3["101110"] = "14";
    sub3["101111"] = "7";

    sub3["110000"] = "1";
    sub3["110001"] = "10";
    sub3["110010"] = "13";
    sub3["110011"] = "0";
    sub3["110100"] = "6";
    sub3["110101"] = "9";
    sub3["110110"] = "8";
    sub3["110111"] = "7";
    sub3["111000"] = "4";
    sub3["111001"] = "15";
    sub3["111010"] = "14";
    sub3["111011"] = "3";
    sub3["111100"] = "11";
    sub3["111101"] = "5";
    sub3["111110"] = "2";
    sub3["111111"] = "12";

    //-------------------------------------------------------

    sub4["000000"] = "7";
    sub4["000001"] = "13";
    sub4["000010"] = "14";
    sub4["000011"] = "3";
    sub4["000100"] = "0";
    sub4["000101"] = "6";
    sub4["000110"] = "9";
    sub4["000111"] = "10";
    sub4["001000"] = "1";
    sub4["001001"] = "2";
    sub4["001010"] = "8";
    sub4["001011"] = "5";
    sub4["001100"] = "11";
    sub4["001101"] = "12";
    sub4["001110"] = "4";
    sub4["001111"] = "15";

    sub4["010000"] = "13";
    sub4["010001"] = "8";
    sub4["010010"] = "11";
    sub4["010011"] = "5";
    sub4["010100"] = "6";
    sub4["010101"] = "15";
    sub4["010110"] = "0";
    sub4["010111"] = "3";
    sub4["011000"] = "4";
    sub4["011001"] = "7";
    sub4["011010"] = "2";
    sub4["011011"] = "12";
    sub4["011100"] = "1";
    sub4["011101"] = "10";
    sub4["011110"] = "14";
    sub4["011111"] = "9";

    sub4["100000"] = "10";
    sub4["100001"] = "6";
    sub4["100010"] = "9";
    sub4["100011"] = "0";
    sub4["100100"] = "12";
    sub4["100101"] = "11";
    sub4["100110"] = "7";
    sub4["100111"] = "13";
    sub4["101000"] = "15";
    sub4["101001"] = "1";
    sub4["101010"] = "3";
    sub4["101011"] = "14";
    sub4["101100"] = "5";
    sub4["101101"] = "2";
    sub4["101110"] = "8";
    sub4["101111"] = "4";

    sub4["110000"] = "3";
    sub4["110001"] = "15";
    sub4["110010"] = "0";
    sub4["110011"] = "6";
    sub4["110100"] = "10";
    sub4["110101"] = "1";
    sub4["110110"] = "13";
    sub4["110111"] = "8";
    sub4["111000"] = "9";
    sub4["111001"] = "4";
    sub4["111010"] = "5";
    sub4["111011"] = "11";
    sub4["111100"] = "12";
    sub4["111101"] = "7";
    sub4["111110"] = "2";
    sub4["111111"] = "14";

    //---------------------------------------------------------------------

    sub5["000000"] = "2";
    sub5["000001"] = "12";
    sub5["000010"] = "4";
    sub5["000011"] = "1";
    sub5["000100"] = "7";
    sub5["000101"] = "10";
    sub5["000110"] = "11";
    sub5["000111"] = "6";
    sub5["001000"] = "8";
    sub5["001001"] = "5";
    sub5["001010"] = "3";
    sub5["001011"] = "15";
    sub5["001100"] = "13";
    sub5["001101"] = "0";
    sub5["001110"] = "14";
    sub5["001111"] = "9";

    sub5["010000"] = "14";
    sub5["010001"] = "11";
    sub5["010010"] = "2";
    sub5["010011"] = "12";
    sub5["010100"] = "4";
    sub5["010101"] = "7";
    sub5["010110"] = "13";
    sub5["010111"] = "1";
    sub5["011000"] = "5";
    sub5["011001"] = "0";
    sub5["011010"] = "15";
    sub5["011011"] = "10";
    sub5["011100"] = "3";
    sub5["011101"] = "9";
    sub5["011110"] = "8";
    sub5["011111"] = "6";

    sub5["100000"] = "4";
    sub5["100001"] = "2";
    sub5["100010"] = "1";
    sub5["100011"] = "11";
    sub5["100100"] = "10";
    sub5["100101"] = "13";
    sub5["100110"] = "7";
    sub5["100111"] = "8";
    sub5["101000"] = "15";
    sub5["101001"] = "9";
    sub5["101010"] = "12";
    sub5["101011"] = "5";
    sub5["101100"] = "6";
    sub5["101101"] = "3";
    sub5["101110"] = "0";
    sub5["101111"] = "14";

    sub5["110000"] = "11";
    sub5["110001"] = "8";
    sub5["110010"] = "12";
    sub5["110011"] = "7";
    sub5["110100"] = "1";
    sub5["110101"] = "14";
    sub5["110110"] = "2";
    sub5["110111"] = "13";
    sub5["111000"] = "6";
    sub5["111001"] = "15";
    sub5["111010"] = "0";
    sub5["111011"] = "9";
    sub5["111100"] = "10";
    sub5["111101"] = "4";
    sub5["111110"] = "5";
    sub5["111111"] = "3";

    //----------------------------------------------------------------

    sub6["000000"] = "12";
    sub6["000001"] = "1";
    sub6["000010"] = "10";
    sub6["000011"] = "15";
    sub6["000100"] = "9";
    sub6["000101"] = "2";
    sub6["000110"] = "6";
    sub6["000111"] = "8";
    sub6["001000"] = "0";
    sub6["001001"] = "13";
    sub6["001010"] = "3";
    sub6["001011"] = "4";
    sub6["001100"] = "14";
    sub6["001101"] = "7";
    sub6["001110"] = "5";
    sub6["001111"] = "11";

    sub6["010000"] = "10";
    sub6["010001"] = "15";
    sub6["010010"] = "4";
    sub6["010011"] = "2";
    sub6["010100"] = "7";
    sub6["010101"] = "12";
    sub6["010110"] = "9";
    sub6["010111"] = "5";
    sub6["011000"] = "6";
    sub6["011001"] = "1";
    sub6["011010"] = "13";
    sub6["011011"] = "14";
    sub6["011100"] = "0";
    sub6["011101"] = "11";
    sub6["011110"] = "3";
    sub6["011111"] = "8";

    sub6["100000"] = "9";
    sub6["100001"] = "14";
    sub6["100010"] = "15";
    sub6["100011"] = "5";
    sub6["100100"] = "2";
    sub6["100101"] = "8";
    sub6["100110"] = "12";
    sub6["100111"] = "3";
    sub6["101000"] = "7";
    sub6["101001"] = "0";
    sub6["101010"] = "4";
    sub6["101011"] = "10";
    sub6["101100"] = "1";
    sub6["101101"] = "13";
    sub6["101110"] = "11";
    sub6["101111"] = "6";

    sub6["110000"] = "4";
    sub6["110001"] = "3";
    sub6["110010"] = "2";
    sub6["110011"] = "12";
    sub6["110100"] = "9";
    sub6["110101"] = "5";
    sub6["110110"] = "15";
    sub6["110111"] = "10";
    sub6["111000"] = "11";
    sub6["111001"] = "14";
    sub6["111010"] = "1";
    sub6["111011"] = "7";
    sub6["111100"] = "6";
    sub6["111101"] = "0";
    sub6["111110"] = "8";
    sub6["111111"] = "13";

    //-------------------------------------------------------------------

    sub7["000000"] = "4";
    sub7["000001"] = "11";
    sub7["000010"] = "2";
    sub7["000011"] = "14";
    sub7["000100"] = "15";
    sub7["000101"] = "0";
    sub7["000110"] = "8";
    sub7["000111"] = "13";
    sub7["001000"] = "3";
    sub7["001001"] = "12";
    sub7["001010"] = "9";
    sub7["001011"] = "7";
    sub7["001100"] = "5";
    sub7["001101"] = "10";
    sub7["001110"] = "6";
    sub7["001111"] = "1";

    sub7["010000"] = "13";
    sub7["010001"] = "0";
    sub7["010010"] = "11";
    sub7["010011"] = "7";
    sub7["010100"] = "4";
    sub7["010101"] = "9";
    sub7["010110"] = "1";
    sub7["010111"] = "10";
    sub7["011000"] = "14";
    sub7["011001"] = "3";
    sub7["011010"] = "5";
    sub7["011011"] = "12";
    sub7["011100"] = "2";
    sub7["011101"] = "15";
    sub7["011110"] = "8";
    sub7["011111"] = "6";

    sub7["100000"] = "1";
    sub7["100001"] = "4";
    sub7["100010"] = "11";
    sub7["100011"] = "13";
    sub7["100100"] = "12";
    sub7["100101"] = "3";
    sub7["100110"] = "7";
    sub7["100111"] = "14";
    sub7["101000"] = "10";
    sub7["101001"] = "15";
    sub7["101010"] = "6";
    sub7["101011"] = "8";
    sub7["101100"] = "0";
    sub7["101101"] = "5";
    sub7["101110"] = "9";
    sub7["101111"] = "2";

    sub7["110000"] = "6";
    sub7["110001"] = "11";
    sub7["110010"] = "13";
    sub7["110011"] = "8";
    sub7["110100"] = "1";
    sub7["110101"] = "4";
    sub7["110110"] = "10";
    sub7["110111"] = "7";
    sub7["111000"] = "9";
    sub7["111001"] = "5";
    sub7["111010"] = "0";
    sub7["111011"] = "15";
    sub7["111100"] = "14";
    sub7["111101"] = "2";
    sub7["111110"] = "3";
    sub7["111111"] = "12";

    //----------------------------------------------------------------

    sub8["000000"] = "13";
    sub8["000001"] = "2";
    sub8["000010"] = "8";
    sub8["000011"] = "4";
    sub8["000100"] = "6";
    sub8["000101"] = "15";
    sub8["000110"] = "11";
    sub8["000111"] = "1";
    sub8["001000"] = "10";
    sub8["001001"] = "9";
    sub8["001010"] = "3";
    sub8["001011"] = "14";
    sub8["001100"] = "5";
    sub8["001101"] = "0";
    sub8["001110"] = "12";
    sub8["001111"] = "7";

    sub8["010000"] = "1";
    sub8["010001"] = "15";
    sub8["010010"] = "13";
    sub8["010011"] = "8";
    sub8["010100"] = "10";
    sub8["010101"] = "3";
    sub8["010110"] = "7";
    sub8["010111"] = "4";
    sub8["011000"] = "12";
    sub8["011001"] = "5";
    sub8["011010"] = "6";
    sub8["011011"] = "11";
    sub8["011100"] = "0";
    sub8["011101"] = "14";
    sub8["011110"] = "9";
    sub8["011111"] = "2";

    sub8["100000"] = "7";
    sub8["100001"] = "11";
    sub8["100010"] = "4";
    sub8["100011"] = "1";
    sub8["100100"] = "9";
    sub8["100101"] = "12";
    sub8["100110"] = "14";
    sub8["100111"] = "2";
    sub8["101000"] = "0";
    sub8["101001"] = "6";
    sub8["101010"] = "10";
    sub8["101011"] = "13";
    sub8["101100"] = "15";
    sub8["101101"] = "3";
    sub8["101110"] = "5";
    sub8["101111"] = "8";

    sub8["110000"] = "2";
    sub8["110001"] = "1";
    sub8["110010"] = "14";
    sub8["110011"] = "7";
    sub8["110100"] = "4";
    sub8["110101"] = "10";
    sub8["110110"] = "8";
    sub8["110111"] = "13";
    sub8["111000"] = "15";
    sub8["111001"] = "12";
    sub8["111010"] = "9";
    sub8["111011"] = "0";
    sub8["111100"] = "3";
    sub8["111101"] = "5";
    sub8["111110"] = "6";
    sub8["111111"] = "11";

    string hexas[8];
    for (int i = 0; i < bin.length(); i += 6) {
        for (int j = i; j < i + 6; j++) {
            hexas[i/6] += bin[j];
        }
    }

    for (int i = 0; i < 8; i++) {
        string current = hexas[i];
        string terminals = "";
        string core = "";
        // Isolation terminal and core
        for (int j = 0; j < current.length(); j++) {
            if (j == 0 || j == current.length() - 1) {
                terminals += current[j];
            }else {
                core += current[j];
            }
        }
        if (i == 0) {
            retVal += decimalToBinary(sub1[terminals + core]);
        }else if (i == 1) {
            retVal += decimalToBinary(sub2[terminals + core]);
        }else if (i == 2) {
            retVal += decimalToBinary(sub3[terminals + core]);
        }else if (i == 3) {
            retVal += decimalToBinary(sub4[terminals + core]);
        }else if (i == 4) {
            retVal += decimalToBinary(sub5[terminals + core]);
        }else if (i == 5) {
            retVal += decimalToBinary(sub6[terminals + core]);
        }else if (i == 6) {
            retVal += decimalToBinary(sub7[terminals + core]);
        }else if (i == 7) {
            retVal += decimalToBinary(sub8[terminals + core]);
        }
    }

    return retVal;
}

string F(string rightData, string permutedChoice2Key) {
    string expandedPermutation = expansionPermutation(rightData);
    string xored = xorS(expandedPermutation, permutedChoice2Key);
    string subed = sbox(xored);
    string retVal = permutation(subed);
    return retVal;
}

// round Takes 64 bit Binary data and Binary 56 bit key and Returns 
void roundEncrypt(int roundNum, string *rightData, string *leftData, string *rightKey, string *leftKey) {
    // definitions
    map<int, int> shiftBits;
    shiftBits[1] = 1;
    shiftBits[2] = 1;
    shiftBits[3] = 2;
    shiftBits[4] = 2;
    shiftBits[5] = 2;
    shiftBits[6] = 2;
    shiftBits[7] = 2;
    shiftBits[8] = 2;
    shiftBits[9] = 1;
    shiftBits[10] = 2;
    shiftBits[11] = 2;
    shiftBits[12] = 2;
    shiftBits[13] = 2;
    shiftBits[14] = 2;
    shiftBits[15] = 2;
    shiftBits[16] = 1;

    // left circular shift phase
    string shiftedLeftKey = leftCircularShift(*leftKey, shiftBits[roundNum]);
    string shiftedRightKey = leftCircularShift(*rightKey, shiftBits[roundNum]);

    // permuting choice 2 for key
    string permutedChoice2Key = permutedChoice2(shiftedLeftKey + shiftedRightKey);

    // F phase
    string f = F(*rightData, permutedChoice2Key);

    // round end phase
    string rightNext = xorS(*leftData, f);
    string leftNext = *rightData;
    
    // output phase
    *leftKey = shiftedLeftKey;
    *rightKey = shiftedRightKey;
    *rightData = rightNext;
    *leftData = leftNext;
}

string generatingCipherTextAfterRounds(string leftData, string rightData) {
    string swapped = swap32bit(leftData + rightData);
    string inverseInitial = inverseInitialPermutation(swapped);
    string cipherText = binaryToHexa(inverseInitial);
    return cipherText;
}

string encrypt(string data, string key) {
    // permuted choice 1
    string binKey = hexaToBinary(key);
    string key56 = permutedChoice1(binKey);

    // splitting key after permuted choice 1
    string leftKey = "";
    string rightKey = "";
    for (int i = 0; i < key56.length() / 2; i++) {
        leftKey += key56[i];
    }
    for (int i = key56.length() / 2; i < key56.length(); i++) {
        rightKey += key56[i];
    }

    // data initial permutation
    string binData = hexaToBinary(data);
    string permutedData = initialPermutation(binData);

    // splitting data after initial permutation
    string rightData = "";
    string leftData = "";
    for (int i = 0; i < permutedData.length() / 2; i++) {
        leftData += permutedData[i];
    }
    for (int i = permutedData.length() / 2; i < permutedData.length(); i++) {
        rightData += permutedData[i];
    }

    // CALLING ROUNDS
    for (int i = 1; i <= 16; i++) {
        roundEncrypt(i, &rightData, &leftData, &rightKey, &leftKey);
    }

    // Generating cipher text
    string cipherText = generatingCipherTextAfterRounds(leftData, rightData);

    return cipherText;
}


// FOR DECRYPTION

void generating16PermutedChoice2Keys(string key, string permutedChoice2Keys[]) {
    // permuted choice 1
    string binKey = hexaToBinary(key);
    string key56 = permutedChoice1(binKey);

    // splitting key after permuted choice 1
    string leftKey = "";
    string rightKey = "";
    for (int i = 0; i < key56.length() / 2; i++) {
        leftKey += key56[i];
    }
    for (int i = key56.length() / 2; i < key56.length(); i++) {
        rightKey += key56[i];
    }

    // generating 16 permuted choice 2 keys
    map<int, int> shiftBits;
    shiftBits[1] = 1;
    shiftBits[2] = 1;
    shiftBits[3] = 2;
    shiftBits[4] = 2;
    shiftBits[5] = 2;
    shiftBits[6] = 2;
    shiftBits[7] = 2;
    shiftBits[8] = 2;
    shiftBits[9] = 1;
    shiftBits[10] = 2;
    shiftBits[11] = 2;
    shiftBits[12] = 2;
    shiftBits[13] = 2;
    shiftBits[14] = 2;
    shiftBits[15] = 2;
    shiftBits[16] = 1;
    for (int i = 1; i <= 16; i++) {
        leftKey = leftCircularShift(leftKey, shiftBits[i]);
        rightKey = leftCircularShift(rightKey, shiftBits[i]);
        permutedChoice2Keys[i - 1] = permutedChoice2(leftKey + rightKey);
    }
}

string decrypt(string data, string key) {
    // Getting all permuted keys
    string permutedChoice2Keys[16];
    generating16PermutedChoice2Keys(key, permutedChoice2Keys);

    // setting the cipher before the rounds
    string binData = hexaToBinary(data);
    string initialPerm = initialPermutation(hexaToBinary(data));
    string swapped = swap32bit(initialPerm);

    string leftData = "";
    string rightData = "";
    for (int i = 0; i < swapped.length() / 2; i++) {
        leftData += swapped[i];
    }
    for (int i = swapped.length() / 2; i < swapped.length(); i++) {
        rightData += swapped[i];
    }

    for (int i = 15; i >= 0; i--) {
        string afterF = F(leftData, permutedChoice2Keys[i]);
        string leftNext = xorS(afterF, rightData);
        rightData = leftData;
        leftData = leftNext;
    }

    string binaryText = inverseInitialPermutation(leftData + rightData);
    string text = binaryToHexa(binaryText);
    return text;
}

int main(int argc, char** argv)
{
    
    // input phase
    string method = argv[1];
    string data = argv[2];
    string key = argv[3];
    


    // extend the input data to 64 bits by adding zeros to the left
    if (data.length() < 16) {
        string extraZeros = "";
        for (int i = 0; i < 16 - data.length(); i++) {
            extraZeros += "0";
        }
        data = extraZeros + data;
    }
    
    

    // extend the input key to 64 bits by adding zeros to the left
    if (key.length() < 16) {
        string extraZeros = "";
        for (int i = 0; i < 16 - key.length(); i++) {
            extraZeros += "0";
        }
        key = extraZeros + key;
    }


    
    // processing and output phase
    if (method == "encrypt") {
        string cipher = encrypt(data, key);
        cout << "cipher: " << cipher;
    }
    else if(method == "decrypt") {
        string plain = decrypt(data, key);
        cout << "plain: " << plain;
    }
    

    return 0;
}