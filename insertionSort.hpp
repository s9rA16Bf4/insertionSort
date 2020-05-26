#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <vector>

template<typename T>
class insertionSort{
private:
  std::vector<T> internalVector; // This will hold our unsorted and hopefully sorted list

public:
  std::vector<T> getVector(); // Returns internalVector
  void sort(); // Sorts our vector
  void loadVector(std::vector<T> &orginVector);
};

template<typename T>
std::vector<T> insertionSort<T>::getVector(){ return this->internalVector; }

template<typename T>
void insertionSort<T>::loadVector(std::vector<T> &orginVector){
  for(T object:orginVector){
    this->internalVector.push_back(object);
  }
}

template<typename T>
void insertionSort<T>::sort(){
  bool exit = false;
  while(!exit){
    bool perfectRun = true;
    for (unsigned int i = 0; i < (this->internalVector.size()-1); i++){
      if (this->internalVector[i] > this->internalVector[i+1]){
        T temp = this->internalVector[i+1];
        this->internalVector[i+1] = this->internalVector[i];
        this->internalVector[i] = temp;
        perfectRun = false;
      }
    }
    if (perfectRun){ exit = true; }
  }
}


#endif
