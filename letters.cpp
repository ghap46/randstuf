#include <iostream>
#include <string>
#include <stdlib.h>
/*unsigned int randomint()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, 4294967295);
    return distrib(gen);    
}*/
unsigned int tenTo(unsigned int k)
{
    if(k == 0)
    {
        return 1;
    }
    unsigned int ret = 10;
    for(int i = 1; i < k; ++i)
    {
        ret *= 10;
    }
    return ret;
}
unsigned int letVal(char l)
{
    if(l >= 'a' && l <= 'z')
    {
        if(l == 'i' || l == 'r')
        {
            return 9;
        }
        else
        {
            return (l - 96) % 9;
        }
    }
    if(l >= 'A' && l <= 'Z')
    {
        if(l == 'I' || l == 'R')
        {
            return 9;
        }
        else
        {
            return (l - 64) % 9;
        }
    }
    else
    {
        return 0;
    }
}
int main(int argc, char* argv[])
{
    if(argc >= 3)
    {
        std::cout << "The program only supports one word at a time, please re-run." << std::endl;
        return -1;
    }
    std::string word;
    if(argc < 2)
    {
        std::cout << "Type in the word to calculate: >";
        std::cin >> word;
    }
    else
    {
        word = argv[1];
    }
    /*for(int i = 0; i < word.size(); ++i)
    {
        std::cout << "argv[" << word[i] << "] = " << letVal(word[i]) << std::endl; 
    }*/
    unsigned int concNum = 0, sumNum = 0;
    for(int i = 0; i < word.size(); ++i)
    {
        concNum += tenTo(word.size() - i - 1) * letVal(word[i]);
        sumNum += letVal(word[i]);
    }
    std::cout << "Concatenation -> " << concNum << std::endl;
    std::cout << "Sum -> " << sumNum << std::endl;
}