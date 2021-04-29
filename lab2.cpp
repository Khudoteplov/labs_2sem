#include<iostream>
#include<cstring>


struct String{
    char *cstr;
    unsigned len;
    unsigned real_len;
};


String new_string(char const *cstr){
    String tmp;
    tmp.len = strlen(cstr);
    tmp.cstr = new char[2*tmp.len+1];
    tmp.real_len = 2*tmp.len+1;
    strcpy(tmp.cstr, cstr);
    return tmp;
}


String new_string(){
    String tmp;
    tmp.len =0 ;
    tmp.cstr= 0 ;
    tmp.real_len  =0;
    return tmp;
}


String new_string(String const &src){
    String tmp;
    tmp.len = src.len;
    tmp.cstr = new char[2*tmp.len+1];
    tmp.real_len = 2*tmp.len+1;
    strcpy(tmp.cstr, src.cstr);
    return tmp;
}


void delete_string(String &str){

    delete[] (str.cstr);
    str.len = 0;
    str.real_len = 0;

}


unsigned length(String const &str){
    return str.len;
}


String& copy(String &dst, String const &src){
    auto tmp = new char[2*dst.len + 1];
    strcpy(tmp, src.cstr);
    delete[] dst.cstr; dst.cstr = tmp; dst.len = src.len; dst.real_len=2*dst.len + 1;
    return dst;
}


char get_char_at(String const &str, unsigned pos){
    return str.cstr[pos];
}


String& set_char_at(String &str, unsigned pos, char c){
    str.cstr[pos]=c;
    return str;
}


String& append(String &dst, char const *cstr){
    unsigned tmp_len=dst.len;
    unsigned add_len=strlen(cstr);
    dst.len += add_len;
    if (dst.real_len <= dst.len) {
        char *tmp = dst.cstr;
        dst.cstr = new char[2*dst.len + 1];
        dst.real_len = 2*dst.len + 1;
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;
    }
    else{
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
    }
    return dst;
}


String& append(String &dst, String const &src){
    return append(dst, src.cstr);
}


void print(String const &str){
    std::cout << str.cstr;
}



