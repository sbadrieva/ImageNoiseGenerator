//
//  NoiseClass.hpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 3/15/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#ifndef NoiseClass_hpp
#define NoiseClass_hpp

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


bool addGaussianNoise(const Mat src, Mat &dst, double Mean, double StdDev);
bool addSaltAndPepperNoise(const Mat src, Mat &dst, int count, int size);
bool addSpeckleNoise(const Mat src, Mat &dst,int count,int size);
bool addPepper(const Mat src, Mat &dst,int count,int size);
bool addSalt(const Mat src, Mat &dst,int count,int size);
bool addPeriodicNoise(const Mat src, Mat &dst);

#endif /* NoiseClass_hpp */
