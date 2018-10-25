//
//  main.cpp
//  KNN
//
//  Created by ychen on 2018/10/23.
//  Copyright © 2018年 ychen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
struct Data{
    double x, y;
    Data(double x=0, double y=0){
        this->x = x;
        this->y = y;
    }
};

class KNN{
public:
    // prediction
    int run_knn(vector<Data> &dataset, vector<int> &labels, Data data ,int K){
        vector<pair<double,int>> dist_labels; // record (distance,lable)pair
        // calculate distance between data and each element in dataset
        for(int i = 0; i < dataset.size(); i++){
            dist_labels.push_back({cal_distance(dataset[i], data), labels[i]});
        }
        // find K closet data
        find_closet_data(dist_labels, K);
        // vote: the data belongs to most type in the K closet data
        unordered_map<int, int> label_cnt; // (label,cnt)
        int maxCnt = 0, predict_label = -1;
        for(int i = 0; i < K; i++){
            label_cnt[dist_labels[i].second]++;
            if(label_cnt[dist_labels[i].second] > maxCnt){
                maxCnt = label_cnt[dist_labels[i].second];
                predict_label = dist_labels[i].second;
            }
        }
        return predict_label;
    }
private:
    // find closet K data points in training data and restore them in first K elements in dist_labels
    // dist_labels:store pair (the distance between data and training data, label of training data)
    void find_closet_data(vector<pair<double,int>>& dist_labels, int K){
        int start = 0, end = dist_labels.size() - 1;
        int pos;
        while((pos=partition(dist_labels, start, end)) != K - 1){
            if(pos < K - 1)
                start = pos + 1;
            else
                end = pos - 1;
        }
    }
    
    int partition(vector<pair<double,int>>& dist_labels, int start, int end){
        pair<double, int> pivot = dist_labels[end];
        int p = start - 1; // index of last element not larger than pivot
        for(int i = start; i < end - 1; i++){
            if(dist_labels[i].first <= pivot.first){
                p++;
                swap(dist_labels[i], dist_labels[p]);
            }
        }
        swap(dist_labels[++p], dist_labels[end]);
        return p;
    }
    
    double cal_distance(Data &d1, Data &d2){
        return sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
    }

};


int main(int argc, const char * argv[]) {
    vector<Data> dataset;
    dataset.push_back(Data(1.0, 2.0));
    dataset.push_back(Data(1.2, 0.1));
    dataset.push_back(Data(0.1, 1.4));
    dataset.push_back(Data(0.3, 3.5));
    vector<int> labels;
    labels.push_back(1);
    labels.push_back(1);
    labels.push_back(2);
    labels.push_back(2);
    KNN knn;
    cout << "predict..." << endl;
    cout << "Data(1.1,0.3) type: "<<knn.run_knn(dataset, labels, Data(1.1,0.3), 3) << endl;
    return 0;
}
