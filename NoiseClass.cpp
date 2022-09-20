//
//  NoiseClass.cpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 3/15/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#include "NoiseClass.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool addGaussianNoise(const Mat src, Mat &dst, double Mean, double StdDev)
{
    if(src.empty())
    {
        cout<<"Empty Image";
        return false;
    }
    Mat newSource;
    Mat gaussNoise;
    if(src.channels()==1){
        gaussNoise= Mat(src.size(),CV_16SC1);
    }
    else if(src.channels()==3){
        gaussNoise=Mat(src.size(),CV_16SC3);
    }
    
    randn(gaussNoise,Scalar::all(Mean), Scalar::all(StdDev));
    
    src.convertTo(newSource,CV_16SC3);
    addWeighted(newSource, 1.0, gaussNoise, 1.0, 0.0, newSource);
    
    newSource.convertTo(dst,src.type());
    
    return true;
    
}


bool addSaltAndPepperNoise(const Mat src, Mat &dst, int count, int size){
    
    //count is how many salt and peppers. Size is size of each noise.
    
    if(src.empty())
    {
        cout<<"Empty Image";
        return false;
    }
    
    dst.create(src.size(), src.type());
    Mat newSource;
    src.convertTo(newSource, src.type());
    dst = newSource;
    
    int x;
    int y;
    int psNoise;
    while (count)
    {
        x = rand() % (newSource.rows - size + 1);
        y = rand() % (newSource.cols - size + 1);
        psNoise = rand() % 2;
        if (psNoise)                                     // Create salt spots
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    dst.at<uchar>(x + i, y + j) = 255;
                }
            }
        else                                            // Create pepper spots
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    dst.at<uchar>(x + i, y + j) = 0;
                }
            }
        count = count - 1;
    }
    
    return true;
}


bool addSpeckleNoise(const Mat src, Mat &dst,int count,int size){
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    dst.create(src.size(), src.type());
    
    Mat newSource;
    src.convertTo(newSource, src.type());
    dst = newSource;
    
    int x;
    int y;
    
    while (count)
    {
        x = rand() % (newSource.rows - size + 1);
        y = rand() % (newSource.cols - size + 1);
        // Create salt spots
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                dst.at<uchar>(x + i, y + j) = dst.at<uchar>(x + i, y + j)*(rand()%100);
            }
        }
        
        count = count - 1;
    }
    
    return true;
}

bool addPepper(const Mat src, Mat &dst,int count,int size){
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    dst.create(src.size(), src.type());
    
    Mat newSource;
    src.convertTo(newSource, src.type());
    dst = newSource;
    
    int x;
    int y;
    
    while (count)
    {
        x = rand() % (newSource.rows - size + 1);
        y = rand() % (newSource.cols - size + 1);
        // Create salt spots
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                dst.at<uchar>(x + i, y + j) = dst.at<uchar>(x + i, y + j)=0;
            }
        }
        
        count = count - 1;
    }
    
    return true;
}

bool addSalt(const Mat src, Mat &dst,int count,int size){
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    dst.create(src.size(), src.type());
    
    Mat newSource;
    src.convertTo(newSource, src.type());
    dst = newSource;
    
    int x;
    int y;
    
    while (count)
    {
        x = rand() % (newSource.rows - size + 1);
        y = rand() % (newSource.cols - size + 1);
        // Create salt spots
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                dst.at<uchar>(x + i, y + j) = dst.at<uchar>(x + i, y + j)=255;
            }
        }
        
        count = count - 1;
    }
    
    return true;
}

bool addPeriodicNoise(const Mat src, Mat &dst){
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    dst.create(src.size(), src.type());
    
    
    Mat newSource;
    src.convertTo(newSource, src.type());
    dst = newSource;
    
    int width =newSource.cols;
    int height=newSource.rows;
    for( int i=0;i<height;i++){
        for ( int j=0;j<width;j++){
            dst.at<uchar>(i,j)=newSource.at<uchar>(i,j)+40*sin(40*i)+40*sin(40*j);
        }
    }
    
    return true;
}
