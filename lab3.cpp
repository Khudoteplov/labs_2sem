#include <chrono>
#include <iostream>

#include "lab1.cpp"
#include "lab2.cpp"


struct String1{
    char *cstr;
    unsigned len;
    unsigned real_len;
};


String1 new_string1(char const *cstr){
    String1 *tmp = new String1;
    tmp->len = strlen(cstr);
    tmp->cstr = new char[tmp->len+1];
    tmp->real_len = tmp->len+1;
    strcpy(tmp->cstr, cstr);
    return *tmp;
}


String1 new_string1(){
    String1 *tmp = new String1;
    tmp->len =0 ;
    tmp->cstr= 0 ;
    tmp->real_len  =0;
    return *tmp;
}


String1 new_string1(String1 const &src){
    auto tmp = new String1;
    tmp->len = src.len;
    tmp->cstr = new char[tmp->len+1];
    tmp->real_len = tmp->len+1;
    strcpy(tmp->cstr, src.cstr);
    return *tmp;
}


void delete_string1(String1 &str){

    delete[] (str.cstr);
}


unsigned length1(String1 const &str){
    return str.len;
}


String1& copy1(String1 &dst, String1 const &src){
    delete dst.cstr;
    dst.len=src.len;


    dst.cstr= new char[dst.len + 1];
    dst.real_len = dst.len + 1;
    strcpy(dst.cstr, src.cstr);
    return dst;
}



String1& append1(String1 &dst, char const *cstr){
    unsigned tmp_len=dst.len;
    unsigned add_len=strlen(cstr);
    dst.len += add_len;

        char *tmp = dst.cstr;
        dst.cstr = new char[dst.len + 1];
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;

    return dst;
}





int main(){
    auto start = std::chrono::steady_clock:: now();
    float sum = 0.f;
    const int64_t y = 40000000;
    //List a = new_list();
    String a = new_string();
    //auto a = new int[y];
    for (long long counter =1; counter != y; ++counter){
        append(a, "a");
        //push_list(a,29);
        //a[counter] = 29;
    }
    //for (long long counter =1; counter != y; ++counter){

        //pop_list(a);
        //a[counter] = 0;
    //}

    auto stop = std::chrono::steady_clock::now();
    auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    std::cout << sum << "  "<< duration << std::endl;
}

