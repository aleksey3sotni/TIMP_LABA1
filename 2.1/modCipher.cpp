#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "modAlphaCipher.h"

class modAlphaCipher {
public:
    explicit modAlphaCipher(const std::wstring& inputKey);
    std::wstring encrypt(const std::wstring& plainText);
    std::wstring decrypt(const std::wstring& cipherText);

private:
    std::vector<int> mapToIndices(const std::wstring& text);
    std::wstring mapToChars(const std::vector<int>& indices);

    std::wstring key;
    static const std::wstring numAlpha; // Assume this is defined somewhere
    static std::unordered_map<wchar_t, int> alphaIndex;
};

modAlphaCipher::modAlphaCipher(const std::wstring& inputKey) {
    for (size_t i = 0; i < numAlpha.size(); ++i) {
        alphaIndex[numAlpha[i]] = static_cast<int>(i);
    }
    key = mapToIndices(inputKey);
}

std::wstring modAlphaCipher::encrypt(const std::wstring& plainText) {
    std::vector<int> indices = mapToIndices(plainText);
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = (indices[i] + key[i % key.size()]) % alphaIndex.size();
    }
    return mapToChars(indices);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipherText) {
    std::vector<int> indices = mapToIndices(cipherText);
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = (indices[i] - key[i % key.size()] + alphaIndex.size()) % alphaIndex.size();
    }
    return mapToChars(indices);
}

std::vector<int> modAlphaCipher::mapToIndices(const std::wstring& text) {
    std::vector<int> result;
    for (const auto& character : text) {
        result.push_back(alphaIndex[character]);
    }
    return result;
}

std::wstring modAlphaCipher::mapToChars(const std::vector<int>& indices) {
    std::wstring result;
    for (const auto& index : indices) {
        result.push_back(numAlpha[index]);
    }
    return result;
}
