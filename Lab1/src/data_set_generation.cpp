#include "data_set_generation.h"

void data_set_generation::random(string filename, string filename2, string filename3, string filename4) {
    ofstream output1(filename);
    ofstream output2(filename2);
    ofstream output3(filename3);
    ofstream output4(filename4);

    srand(time(nullptr));

    for(int i = 0; i < 10; i++) {
        int rand_n = rand() % 10 + 1;
        output1 << rand_n << endl;
    }

    for(int i = 0; i < 1000; i++) {
        int rand_n = rand() % 1000 + 1;
        output2 << rand_n << endl;
    }

    for(int i = 0; i < 10000; i++) {
        int rand_n = rand() % 10000 + 1;
        output3 << rand_n << endl;
    }

    for(int i = 0; i < 100000; i++) {
        int rand_n = rand() % 100000 + 1;
        output4 << rand_n << endl;
    }
}

void data_set_generation::reversed(string filename, string filename2, string filename3, string filename4){
    ofstream output1(filename);
    ofstream output2(filename2);
    ofstream output3(filename3);
    ofstream output4(filename4);

    vector<int> vec1, vec2, vec3, vec4;

    srand(time(nullptr));

    for(int i = 0; i < 10; i++) {
        int rand_n = rand() % 10 + 1;
        vec1.push_back(rand_n);
    }

    reverse(vec1.begin(), vec1.end());

    for(int i = 0; i < 10; i++) {
        output1 << vec1[i] << endl;
    }

    for(int i = 0; i < 1000; i++) {
        int rand_n = rand() % 1000 + 1;
        vec2.push_back(rand_n);
    }

    reverse(vec2.begin(), vec2.end());

    for(int i = 0; i < 1000; i++) {
        output2 << vec2[i] << endl;
    }

    for(int i = 0; i < 10000; i++) {
        int rand_n = rand() % 10000 + 1;
        vec3.push_back(rand_n);
    }

    reverse(vec3.begin(), vec3.end());

    for(int i = 0; i < 10000; i++) {
        output3 << vec3[i] << endl;
    }

    for(int i = 0; i < 100000; i++) {
        int rand_n = rand() % 100000 + 1;
        vec4.push_back(rand_n);
    }

    reverse(vec4.begin(), vec4.end());

    for(int i = 0; i < 100000; i++) {
        output4 << vec4[i] << endl;
    }
}

void data_set_generation::semi_unique(string filename, string filename2, string filename3, string filename4){
    ofstream output1(filename);
    ofstream output2(filename2);
    ofstream output3(filename3);
    ofstream output4(filename4);

    srand(time(nullptr));

    //file1 - datasize: 10
    vector<int> vec1;
    int num_unique = 10 * 0.2;
    int num_gen = 10 - num_unique;
    for(int i = 0; i < num_unique; i++) {
        int rand_n = rand() % 10  + 1;
        vec1.push_back(rand_n);       vec1.push_back(rand_n);
        vec1.push_back(rand_n);       vec1.push_back(rand_n);
        vec1.push_back(rand_n);
    }

    auto rng = std::default_random_engine {};
    std::shuffle(begin(vec1), end(vec1), rng);

    for(int i = 0; i < 10; i++) {
        output1 << vec1[i] << endl; 
    }

    //file2 - dataset size: 1000

    vector<int> vec2;
    int num_unique2 = 1000 * 0.2;
    int num_gen2 = 1000 - num_unique2;
    for(int i = 0; i < num_unique2; i++) {
        int rand_n = rand() % 1000  + 1;
        vec2.push_back(rand_n);       vec2.push_back(rand_n);
        vec2.push_back(rand_n);       vec2.push_back(rand_n);
        vec2.push_back(rand_n);
    }

    std::shuffle(begin(vec2), end(vec2), rng);

    for(int i = 0; i < 1000; i++) {
        output2 << vec2[i] << endl; 
    }

    //file3 - dataset size: 10000

    vector<int> vec3;
    int num_unique3 = 10000 * 0.2;
    int num_gen3 = 10000 - num_unique3;
    for(int i = 0; i < num_unique3; i++) {
        int rand_n = rand() % 10000  + 1;
        vec3.push_back(rand_n);       vec3.push_back(rand_n);
        vec3.push_back(rand_n);       vec3.push_back(rand_n);
        vec3.push_back(rand_n);
    }

    std::shuffle(begin(vec3), end(vec3), rng);

    for(int i = 0; i < 10000; i++) {
        output3 << vec3[i] << endl; 
    }

    //file4 - dataset size: 100000

    vector<int> vec4;
    int num_unique4 = 100000 * 0.2;
    int num_gen4 = 100000 - num_unique4;
    for(int i = 0; i < num_unique4; i++) {
        int rand_n = rand() % 100000  + 1;
        vec4.push_back(rand_n);       vec4.push_back(rand_n);
        vec4.push_back(rand_n);       vec4.push_back(rand_n);
        vec4.push_back(rand_n);
    }

    std::shuffle(begin(vec4), end(vec4), rng);

    for(int i = 0; i < 100000; i++) {
        output4 << vec4[i] << endl; 
    }
}

void data_set_generation::semi_sorted(string filename, string filename2, string filename3, string filename4){
    ofstream output1(filename);
    ofstream output2(filename2);
    ofstream output3(filename3);
    ofstream output4(filename4);

    srand(time(nullptr));
    auto rng = std::default_random_engine {};

    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;
    vector<int> vec4;

    for(int i = 0; i < 10; i++) {
        int rand_n = rand() % 10 + 1;
        vec1.push_back(rand_n);
    }

    std::sort(vec1.begin(), vec1.end());

    int wrap_number = 10 - 10 / 3;
    int rand_1 = rand() % wrap_number + 1;
    std::shuffle(vec1.begin() + rand_1, vec1.begin() + rand_1 + 2, rng);

    for(int i = 0; i < 10; i++) {
        output1 << vec1[i] << endl; 
    }

    for(int i = 0; i < 1000; i++) {
        int rand_n = rand() % 1000 + 1;
        vec2.push_back(rand_n);
    }

    std::sort(vec2.begin(), vec2.end());

    int wrap_number2 = 1000 - 1000 / 3;
    int rand_2 = rand() % wrap_number2 + 1;
    std::shuffle(vec2.begin() + rand_2, vec2.begin() + rand_2 + 300, rng);

    for(int i = 0; i < 1000; i++) {
        output2 << vec2[i] << endl; 
    }

    for(int i = 0; i < 10000; i++) {
        int rand_n = rand() % 10000 + 1;
        vec3.push_back(rand_n);
    }

    std::sort(vec3.begin(), vec3.end());

    int wrap_number3 = 10000 - 10000 / 3;
    int rand_3 = rand() % wrap_number3 + 1;
    std::shuffle(vec3.begin() + rand_3, vec3.begin() + rand_3 + 3000, rng);

    for(int i = 0; i < 10000; i++) {
        output3 << vec3[i] << endl; 
    }

    for(int i = 0; i < 100000; i++) {
        int rand_n = rand() % 100000 + 1;
        vec4.push_back(rand_n);
    }

    std::sort(vec4.begin(), vec4.end());

    int wrap_number4 = 100000 - 100000 / 3;
    int rand_4 = rand() % wrap_number4 + 1;
    std::shuffle(vec4.begin() + rand_4, vec4.begin() + rand_4 + 30000, rng);

    for(int i = 0; i < 100000; i++) {
        output4 << vec4[i] << endl; 
    }
}

// string data_types[16] = {
//         "random_10.txt", "reversed_sorted_10.txt", "20_unique_10.txt", "30_random_10.txt",
//         "random_1000.txt", "reversed_sorted_1000.txt", "20_unique_1000.txt", "30_random_1000.txt",
//         "random_10000.txt", "reversed_sorted_10000.txt", "20_unique_10000.txt", "30_random_10000.txt",
//         "random_100000.txt", "reversed_sorted_100000.txt", "20_unique_100000.txt", "30_random_100000.txt"
// };

void data_set_generation::generate() {
    random("random_10.txt", "random_1000.txt", "random_10000.txt", "random_100000.txt");
    reversed("reversed_sorted_10.txt", "reversed_sorted_1000.txt", "reversed_sorted_10000.txt", "reversed_sorted_100000.txt");
    semi_unique("20_unique_10.txt", "20_unique_1000.txt", "20_unique_10000.txt", "20_unique_100000.txt");
    semi_sorted("30_random_10.txt", "30_random_1000.txt", "30_random_10000.txt", "30_random_100000.txt");
}