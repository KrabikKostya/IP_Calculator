#ifndef IP_CALCULATOR_IP_CALCULATOR_H
#define IP_CALCULATOR_IP_CALCULATOR_H
#include <string>

class IP_Calculator {
private:
    IP_Calculator();
    ~IP_Calculator();
    static std::string *split(std::string words);

    static const uint32_t class_A_mask = 0b0000 << 28;
    static const uint32_t class_B_mask = 0b1000 << 28;
    static const uint32_t class_C_mask = 0b1100 << 28;
    static const uint32_t class_D_mask = 0b1110 << 28;
    static const uint32_t class_E_mask = 0b1111 << 28;
    static const uint32_t private_network_class_A_mask = 0b00001010 << 24;
    static const uint32_t private_network_class_B_mask = 0b10101100 << 24;
    static const uint32_t private_network_class_C_mask = 0b1100000010101000 << 16;

public:
    static uint32_t ip_to_number(std::string ip);
    static uint32_t ip_to_number(int ip[4]);
    static std::string ip_to_string(uint32_t ip);
    static uint32_t net_mask(int prefix);
    static uint32_t net_mask(std::string net_mask);
    static uint32_t net_mask(int net_mask[4]);
    static int number_of_host(int prefix);
    static uint32_t network_ip(uint32_t ip_address, uint32_t net_mask);
    static uint32_t broadcast_ip(uint32_t ip_address, uint32_t net_mask);
    static std::string ip_class_check(uint32_t ip_address);
    static std::string ip_type_check(uint32_t ip_address);
    static bool same_network_check(uint32_t firs_host_ip, uint32_t second_host_ip, uint32_t net_mask);
};


#endif //IP_CALCULATOR_IP_CALCULATOR_H
