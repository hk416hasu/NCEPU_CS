#include <openssl/evp.h>
#include <iostream>
#include <cstdio>
#include "md5.h"

std::string compute_md5(const std::string& data) {
    unsigned char digest[EVP_MAX_MD_SIZE]; // EVP_MAX_MD_SIZE 适用于不同哈希算法
    unsigned int digest_len = 0;

    // OpenSSL 3.0，使用 EVP（Envelope Cryptographic Functions）接口来计算 MD5。
    EVP_MD_CTX* ctx = EVP_MD_CTX_new(); // 创建 MD5 上下文
    if (!ctx) {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return "";
    }

    if (EVP_DigestInit_ex(ctx, EVP_md5(), nullptr) != 1 ||
        EVP_DigestUpdate(ctx, data.c_str(), data.size()) != 1 ||
        EVP_DigestFinal_ex(ctx, digest, &digest_len) != 1) {
        std::cerr << "MD5 computation failed" << std::endl;
        EVP_MD_CTX_free(ctx);
        return "";
    }

    EVP_MD_CTX_free(ctx); // 释放 MD5 上下文

    // 将 MD5 结果转换为十六进制字符串
    char md5_str[digest_len * 2 + 1]; 
    for (unsigned int i = 0; i < digest_len; ++i) {
        std::sprintf(&md5_str[i * 2], "%02x", digest[i]);
    }
    md5_str[digest_len * 2] = '\0'; // 添加字符串结束符

    return std::string(md5_str);
}

