# C++ implementation of kNN (k-Nearest-Neighbor) Algorithm
The k-nn algorithm is a simple supervised machine learning algorithm that can be used both for classification and regression. It's an instance-based or lazy algorithm making predictions using a similarity measure.  Instead of estimating a model, it stores all training examples in memory and all computation is deferred until classification or regression.  
Here I only implement KNN for classification.  
## Algorithm
1. Load the data  
2. Initialise the value of k  
3. For getting the predicted class, iterate from 1 to total number of training data points  
    Calculate the distance between test data and each row of training data. Here we will use Euclidean distance as our distance metric since it’s the most popular method. The other metrics that can be used are Chebyshev, cosine, etc.
4. Sort the calculated distances in ascending order based on distance values to get top k rows from the sorted array. 
tips: We can use partition algorithm to get  top k rows with time complexity O(#training data) instead of using sort.
5. Get the most frequent class of these rows  
6. Return the predicted class  
## C++ implementation
[C++ code] ()
