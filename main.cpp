#include <iostream>
#include "Kmeans.h"
#include "vector"

using namespace std;




int main()



{
    /*
    double data[] = {
            0.0, 0.2, 0.4,
            0.3, 0.2, 0.4,
            0.4, 0.2, 0.4,
            0.5, 0.2, 0.4,
            5.0, 5.2, 8.4,
            6.0, 5.2, 7.4,
            4.0, 5.2, 4.4,
            10.3, 10.4, 10.5,
            10.1, 10.6, 10.7,
            11.3, 10.2, 10.9
    };
     */

    ifstream ifile("/Users/cbovigny/Downloads/test.txt",std::ios::in);

    //std::ifstream ifile("example.txt", std::ios::in);
    std::vector<double> data;

    //check to see that the file was opened correctly:
    if (!ifile.is_open()) {
        std::cerr << "There was a problem opening the input file!\n";
        exit(1);//exit or do additional error checking
    }

    double num = 0.0;
    //keep storing values from the text file so long as data exists:
    while (ifile >> num) {
        data.push_back(num);
    }

    double *data2 = data.data();

    //for(int i=0; i<data.size(); i++) {
    //cout <<  data2[i]<<endl;

    //}

    const int size =100; //Number of samples
    const int dim = 6737;   //Dimension of feature
    const int cluster_num = 4; //Cluster number

    KMeans* kmeans = new KMeans(dim,cluster_num);
    int* labels = new int[size];
    kmeans->SetInitMode(KMeans::InitUniform);
    kmeans->Cluster(data2,size,labels);

    for(int i = 0; i < size; ++i)
    {
        printf("%f, %f, %f belongs to %d cluster\n", data2[i*dim+0], data2[i*dim+1], data2[i*dim+2], labels[i]);
       // cout << data2[i*dim+6337] <<endl;
        cout << i << endl;
    }

    delete []labels;
    delete kmeans;

    return 0;
}