#include "Flower.hpp"
#include <utility>
#include <iostream>
#include <string>

//constructor - from point and string
Flower::Flower(const Point &point1, std::string name) :
                    point(point1), type(std::move(name)) { }

Flower::Flower(const std::string &str) : point(std::vector<double>{0}){
    std::vector<double> values;
    int start = 0;
    int end = (int)str.find(',');
    int i = 0;
    while (end != -1) {
        values.emplace_back(std::stod(str.substr(start, end - start)));
        i++;
        start = end + 1;
        end = (int)str.find(',', start);
    }
    point = Point(values);
    type =str.substr(start, end - start);
}


Point& Flower::getPoint(){
    return point;
}

std::string& Flower::getType(){
    return type;
}
std::string Flower::toFileFormat(std::vector<Flower> vec){
    std::string res;
    for(int i = 0;i < vec.size()-1 ; i++) {
        res.append(std::to_string(i) +"   "+ vec[i].getType()+"\n");
    }
    res.append(vec[vec.size()-1].getType());
    return res;
}
std::ostream& operator<<(std::ostream& os, Flower& a){
    os << "[" << a.getPoint() << ", " << a.getType() << "]";
    return os;
}

std::vector<Flower> Flower::toFlowers(std::string const &buffer, char c) {
    std::vector<Flower> vec;
    int start = 0;
    int end = (int)buffer.find(c);
    int i = 0;
    while (end != -1) {
        vec.emplace_back(Flower(buffer.substr(start, end - start)));
        i++;
        start = end + 1;
        end = (int)buffer.find(c, start);
    }
    return std::move(vec);
}
