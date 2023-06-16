#include "IP_Calculator.h"
#include <string>
#include <cmath>

using namespace std;

string *IP_Calculator::split(std::string words) {
    string result[4];
    int position = 0;
    int i = 0;
    while(position < words.size()){
        position = words.find('.');
        result[i] = (words.substr(0,position));
        words.erase(0,position+1); // 3 is the length of the delimiter, "%20"
    }
    return result;
}

string IP_Calculator::join(string *words) {
    string result;
    for (int i = 0; i < 4; ++i) {
        words[i] = words[i].append(".");
        result += words[i];
    }
    return result.substr(0, result.length() - 1);
}

uint32_t IP_Calculator::ip_to_number(string ip){
    string *ip_split = IP_Calculator::split(ip);
    uint32_t result = 0;
    short step = 3;
    for (int i = 0; i < 4; ++i) {
        result += stoi(ip_split[i]) << (step * 8);
        step--;
    }
    return result;
}

uint32_t IP_Calculator::ip_to_number(int ip[4]){
    uint32_t result = 0;
    short step = 3;
    for (int i = 0; i < 4; ++i) {
        result += ip[i] << (step * 8);
        step--;
    }
    return result;
}

string IP_Calculator::ip_to_string(uint32_t ip) {
    string result[4];
    for (int i = 0; i < 4; ++i) {
        result[3 - i] = to_string((ip % 255));
        ip /= 255;
    }
    return IP_Calculator::join(result);
}

uint32_t IP_Calculator::net_mask(int prefix) {
    uint32_t net_mask = 0;
    for (int i = 0; i < prefix; ++i) {
        net_mask <<= 1;
        net_mask++;
    }
    return net_mask << (32 - prefix);
}

uint32_t IP_Calculator::net_mask(string net_mask) {
    uint32_t result = IP_Calculator::ip_to_number(net_mask);
    return result;
}

uint32_t IP_Calculator::net_mask(int net_mask[4]) {
    uint32_t result = IP_Calculator::ip_to_number(net_mask);
    return result;
}

int IP_Calculator::number_of_host(int prefix) {
    return pow(2, 32-prefix) - 2;
}

uint32_t IP_Calculator::network_ip(uint32_t ip_address, uint32_t net_mask) {
    return ip_address & net_mask;
}

uint32_t IP_Calculator::broadcast_ip(uint32_t network_ip_address, uint32_t net_mask) {
    return network_ip_address & ~net_mask;
}

std::string IP_Calculator::ip_class_check(uint32_t ip_address) {
    if((ip_address & IP_Calculator::class_E_mask) == IP_Calculator::class_E_mask)
        return "Class E";
    if((ip_address & IP_Calculator::class_D_mask) == IP_Calculator::class_D_mask)
        return "Class D";
    if((ip_address & IP_Calculator::class_C_mask) == IP_Calculator::class_C_mask)
        return "Class C";
    if((ip_address & IP_Calculator::class_B_mask) == IP_Calculator::class_B_mask)
        return "Class B";
    return "Class A";
}

std::string IP_Calculator::ip_type_check(uint32_t ip_address) {
    if((ip_address & IP_Calculator::private_network_class_C_mask) == IP_Calculator::private_network_class_C_mask)
        return "Class C private network ";
    if((ip_address & IP_Calculator::private_network_class_B_mask) == IP_Calculator::private_network_class_B_mask)
        return "Class B private network ";
    if((ip_address & IP_Calculator::private_network_class_A_mask) == IP_Calculator::private_network_class_A_mask)
        return "Class A private network ";
    return "Public network";
}

bool IP_Calculator::same_network_check(uint32_t firs_host_ip, uint32_t second_host_ip, uint32_t net_mask) {
    return (firs_host_ip & net_mask) == (second_host_ip & net_mask);
}
