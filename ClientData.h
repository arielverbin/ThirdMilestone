#include <string>

/**
 * @brief a class that each client has. The clients use it to save their data.
 * 
 */
class ClientData {
    private:
    std::string trainFile;
    std::string testFile;
    int K;
    std::string destanceMetric;
    // int** matrix;

    public:
    ClientData();

    //get and set for the test file.
    std::string getTestFile();
    void setTestFile(std::string file);

    //get and set for the train file.
    std::string getTrainFile();
    void setTrainFile(std::string file);

    //get and set for the destanceMetric.
    std::string getDestanceMetric();
    void setDestanceMetric(std::string newMatric);

    //get and set for the K.
    int getK();
    void setK(int k);

    // //get and set for the matrix.
    // int** getMatrix();
    // void setMatrix(int** matix);
};