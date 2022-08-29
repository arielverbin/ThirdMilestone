#include <string>

/**
 * @brief a class that each client has. The clients use it to save their data.
 * 
 */
class ClientData {
private:
    std::string trainFile;
    std::string testFile;
    int k;
    std::string distanceMetric;
    std::string classifies;
    int** confusionMatrix;

public:
    ClientData();

    //get and set for the test file.
    std::string getTestFile();
    void setTestFile(std::string file);

    //get and set for the train file.
    std::string getTrainFile();
    void setTrainFile(std::string file);

    //get and set for the distanceMetric.
    std::string getDistanceMetric();
    void setDistanceMetric(std::string newMatric);

    //get and set for the classified points.
    std::string getClassifies();
    void setClassifies(std::string classified);

    //get and set for the K.
    int getK() const;
    void setK(int k);

    //get and set for the matrix.
    int** getConfusionMatrix();
    void setConfusionMatrix(int** matrix);

};