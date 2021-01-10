#include <iostream>
#include <vector>
#include <random>
#include <fstream>

float P(float x, std::vector<float> dataX, std::vector<float> dataY)
{
    if (dataX.size() != dataY.size())
    {
        return 0;
    }

    float FinalVal = 0;
    for (int j = 0; j < dataY.size(); j++)
    {
        float Iloczynup = 1;
        float Iloczyndown = 1;
        for (int i = 0; i < dataX.size() - 1; i++)
        {
            if (i == j)
            {
                //do nothing
            }
            else
            {
                Iloczynup *= x - dataX[i];
            }
        }
        for (int i = 0; i < dataX.size() - 1; i++)
        {
            if (i == j)
            {
                //do nothing
            }
            else
            {
                Iloczyndown *= dataX[j] - dataX[i];
            }
        }
        FinalVal += Iloczynup / Iloczyndown * dataY[j];
    }
    return FinalVal;
}

int main()
{
    //Generate new data
    int N = 5;
    std::vector<float> dataX;
    std::vector<float> dataY;
    for (int i = 0; i < N; i++)
    {
        dataX.push_back(i);
        dataY.push_back(rand() % 10);
    }

    //Display data
    for (int i = 0; i < dataX.size(); i++)
    {
        std::cout << dataX[i] << "<---X Y--->" << dataY[i] << std::endl;
    }

    std::ofstream Filest;
    Filest.open("start_data.txt", std::ios::out);
    for(int i = 0;i<dataX.size();i++)
    {
        Filest << dataX[i] << ":" << dataY[i] <<std::endl;
    }
    Filest.close();

    std::ofstream File;
    File.open("data.txt", std::ios::out);
    for (float k = 0; k <= N;)
    {
        File << k << ":" << P(k, dataX, dataY) << std::endl;
        k += 0.1;
        // std::cout<< k << std::endl;
    }
    File.close();
    return 0;
}

//Conclusion: Used algortim works properly only in the range between min and max x used value,
//Out of this range algoritm gives larger and larger value for next x.