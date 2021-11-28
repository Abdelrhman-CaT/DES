/*
    Author: Abdelrahman Hany
    Created on: 27-Nov-21
*/

#include <stdio.h>
#include <string.h>

#ifdef __GNUC__ 
# define __rdtsc __builtin_ia32_rdtsc 
#else 
# include<intrin.h> 
#endif

using namespace std;

typedef unsigned long long swain;
typedef unsigned char jhin;


/* 
    "The Mutation Must Survive"
                    ~Singed~
*/

swain singed_work(swain input, int input_size, int singed[], int output_size) {
    swain crow = 0;
    for (int shimmer = 0; shimmer < output_size; ++shimmer) {
        crow |= (input >> (input_size - singed[output_size - 1 - shimmer]) & 1) << shimmer;
    }
    return crow;
}


/*
    "Quest accepted! …Wait, where are we going?"
                    ~Ezreal~
*/

swain arcane_shift(swain input, int shift) {
    swain right_wing = input & 0xFFFFFFF;
    swain left_wing = (input >> 28) & 0xFFFFFFF;
    swain shifted_right_wing = ((right_wing << (sizeof(right_wing) * 8 - 28 + shift)) >> (sizeof(right_wing) * 8 - 28)) | (right_wing >> (28 - shift));
    swain shifted_left_wing = ((left_wing << (sizeof(left_wing) * 8 - 28 + shift)) >> (sizeof(left_wing) * 8 - 28)) | (left_wing >> (28 - shift));
    swain crow = (shifted_left_wing << 28) | shifted_right_wing;
    return crow;
}


/*
    "Secrets!!"
                    ~Fiddlesticks~
*/

void generate_keys(swain key, int shifts[] ,int pc1[], int pc1_input_size, int pc1_output_size, int pc2[], 
    int pc2_input_size, int pc2_output_size, swain* keys) {
    swain pc1_key = singed_work(key, pc1_input_size, pc1, pc1_output_size);
    swain pc2_key;
    for (int i = 0; i < 16; i++) {
        pc1_key = arcane_shift(pc1_key, shifts[i]);
        pc2_key = singed_work(pc1_key, pc2_input_size, pc2, pc2_output_size);
        keys[i] = pc2_key;
    }
}



/*
    "Whatever happens, it is on you"
                    ~Vander~
*/

swain get_input(const char* arg) {
    swain crow = 0;
    for (int i = 0;; ++i) {
        jhin unit = arg[i];
        jhin numUnit = unit - '0';
        if (!unit || !(unit >= '0' && unit <= '9' || unit >= 'A' && unit <= 'F' || unit >= 'a' && unit <= 'f')) {
            break;
        }
        crow <<= 4;
        if (numUnit < 10) {
            crow |= numUnit;
        }
        else {
            crow |= (swain)(unit & 0xDF) - 'A' + 10;
        }
    }
    return crow;
}


/*
    "The road to ruin, I've walked it once before"
                    ~Yone~
*/

swain s_box(swain xor_result, int sboxes[]) {
    swain crow = 0;
    for (int i = 0; i < 8; i++) {
        int *box = sboxes + i * 64;
        swain index = xor_result >> (7 - i) * 6 & 0x3F;
        index = index >> 1 & 15 | (index & 1) << 4 | index & 0x20;
        crow |= ((swain)box[index] << (7 - i) * 4);
    }

    return crow;
}


/*
    "Each bullet is a piece of my soul. Each shot is a piece of me"
                    ~Jhin~
*/

swain des_round(swain input, swain key, int exp[], int exp_input_size, int exp_output_size, int perm[], 
    int perm_input_size, int perm_output_size, int sboxes[]) {
    swain left_wing_input = (input >> 32) & 0xFFFFFFFF;
    swain right_wing_input = input & 0xFFFFFFFF;
    swain left_wing_output = right_wing_input;
    swain exp_right_wing_input = singed_work(right_wing_input, exp_input_size, exp, exp_output_size);
    swain xor_with_key = exp_right_wing_input ^ key;
    swain sbox_result = s_box(xor_with_key, sboxes);
    swain permutation_result = singed_work(sbox_result, perm_input_size, perm, perm_output_size);
    swain right_wing_output = permutation_result ^ left_wing_input;
    swain crow = (left_wing_output << 32) | right_wing_output;
    return crow;
}


/*
    "A riddle wrapped in a mystery, hidden within us all"
                    ~The grand general~
*/

swain DES(swain input, swain keys[] ,int ip[], int ip_input_size, int ip_output_size, 
    int exp[], int exp_input_size, int exp_output_size, int sboxes[], int perm[], int perm_input_size, int perm_output_size,
    int iip[], int iip_input_size, int iip_output_size) {
    swain data = singed_work(input, ip_input_size, ip, ip_output_size);
    for (int i = 0; i < 16; i++) {
        data = des_round(data, keys[i], exp, exp_input_size, exp_output_size, perm,
            perm_input_size, perm_output_size, sboxes);
    }
    swain left_data = (data >> 32) & 0xFFFFFFFF;
    swain right_data = data & 0xFFFFFFFF;
    swain swapped = (right_data << 32) | left_data;
    swain crow = singed_work(swapped, iip_input_size, iip, iip_output_size);
    return crow;
}


/*
    "I cannot be good. I must be perfection"
                    ~Jhin~
*/

int main(int argc, char** argv)
{
    // permutation choice 1
    int pc1[56] = { 57,49, 41, 33, 25, 17, 9,
                    1, 58, 50, 42, 34, 26, 18,
                    10, 2, 59, 51, 43, 35, 27,
                    19, 11, 3, 60, 52, 44, 36,
                    63, 55, 47, 39, 31, 23, 15,
                    7, 62, 54, 46, 38, 30, 22,
                    14, 6, 61, 53, 45, 37, 29,
                    21, 13, 5, 28, 20, 12, 4 };
    int pc1_input_size = 64;
    int pc1_output_size = 56;


    // permutation choice 2
    int pc2[48] = { 14, 17, 11, 24, 1, 5,
                    3, 28, 15, 6, 21, 10,
                    23, 19, 12, 4, 26, 8,
                    16, 7, 27, 20, 13, 2,
                    41, 52, 31, 37, 47, 55,
                    30, 40, 51, 45, 33, 48,
                    44, 49, 39, 56, 34, 53,
                    46, 42, 50, 36, 29, 32 };
    int pc2_input_size = 56;
    int pc2_output_size = 48;


    // shift per round
    int shifts[16] = { 1, 1, 2, 2,
                       2, 2, 2, 2,
                       1, 2, 2, 2,
                       2, 2, 2, 1 };


    // initial permuatation
    int ip[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                   60, 52, 44, 36, 28, 20, 12, 4,
                   62, 54, 46, 38, 30, 22, 14, 6, 
                   64, 56, 48, 40, 32, 24, 16, 8,
                   57, 49, 41, 33, 25, 17, 9, 1,
                   59, 51, 43, 35, 27, 19, 11, 3, 
                   61, 53, 45, 37, 29, 21, 13, 5, 
                   63, 55, 47, 39, 31, 23, 15, 7 };
    int ip_input_size = 64;
    int ip_output_size = 64;


    // expansion permutation
    int exp[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                    6, 7, 8, 9, 8, 9, 10, 11,
                    12, 13, 12, 13, 14, 15, 16, 17,
                    16, 17, 18, 19, 20, 21, 20, 21,
                    22, 23, 24, 25, 24, 25, 26, 27,
                    28, 29, 28, 29, 30, 31, 32, 1 };
    int exp_input_size = 32;
    int exp_output_size = 48;


    // permutation
    int perm[32] = { 16, 7, 20, 21,
                    29, 12, 28, 17,
                    1, 15, 23, 26,
                    5, 18, 31, 10,
                    2, 8, 24, 14,
                    32, 27, 3, 9,
                    19, 13, 30, 6,
                    22, 11, 4, 25 };
    int perm_input_size = 32;
    int perm_output_size = 32;

    
    // s-boxes
    int sboxes[512] = {  14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                       0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                       4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                       15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
                       15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                       3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                       0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                       13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,
                       10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                       13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                       13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                       1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 ,
                       7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                       13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                       10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                       3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 ,
                       2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                       14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                       4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                       11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 ,
                       12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                       10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                       9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                       4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 ,
                       4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                       13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                       1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                       6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 ,
                       13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                       1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                       7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                       2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };


    // inverse initial permutation
    int iip[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                    39, 7, 47, 15, 55, 23, 63, 31,
                    38, 6, 46, 14, 54, 22, 62, 30,
                    37, 5, 45, 13, 53, 21, 61, 29,
                    36, 4, 44, 12, 52, 20, 60, 28,
                    35, 3, 43, 11, 51, 19, 59, 27,
                    34, 2, 42, 10, 50, 18, 58, 26,
                    33, 1, 41, 9, 49, 17, 57, 25 };
    int iip_input_size = 64;
    int iip_output_size = 64;

    // ------------------------------------------------------------------------------------------

    char* method = argv[1];
    char* data = argv[2];
    char* key = argv[3];
    
    swain in_key = get_input(key);
    swain in_data = get_input(data);

    swain keys[16];

    generate_keys(in_key, shifts, pc1, pc1_input_size, pc1_output_size, pc2, pc2_input_size, pc2_output_size,
        keys);

    if (strcmp("encrypt", method) == 0) {
        long long t1 = __rdtsc();
        swain cipher = DES(in_data, keys, ip, ip_input_size, ip_output_size, exp, exp_input_size, exp_output_size, sboxes,
            perm, perm_input_size, perm_output_size, iip, iip_input_size, iip_output_size);
        long long t2 = __rdtsc();
        printf("Cipher: %016llX\n", cipher);
        printf("Cycles: %lld\n", t2 - t1);
    }
    else if (strcmp("decrypt", method) == 0) {
        swain reversed_keys[16];
        for (int i = 0; i < 16; i++) {
            reversed_keys[i] = keys[15 - i];
        }
        long long t1 = __rdtsc();
        swain cipher = DES(in_data, reversed_keys, ip, ip_input_size, ip_output_size, exp, exp_input_size, exp_output_size, sboxes,
            perm, perm_input_size, perm_output_size, iip, iip_input_size, iip_output_size);
        long long t2 = __rdtsc();
        printf("Plain: %016llX\n", cipher);
        printf("Cycles: %lld\n", t2 - t1);
    }
    
    return 0;
}