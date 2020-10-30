extern int check(unsigned char key[200]);

void test(unsigned char key[200]) {

    int candidate[256];
    int number[200];
    int pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};


    // search integer by it
    // encoding number by adding number1 * 1 / number2 * 2 / number3 * 4 / number4 * 8 ..
    // then we got right number by encoded with binary
    // 1010 => number4 & number2 is right number
    for(int i = 0; i < 37; i++) {
        int idx = 0;
        for(int j = 0; j < 7; j++) {
            for(int k = 0; k < pow[j] && (7*i + j < 256); k++)
                key[idx++] = 7*i + j;
        }
    }    
    




}