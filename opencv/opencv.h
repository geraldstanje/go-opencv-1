// Copyright 2011 <chaishushan@gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.
//
// OpenCV Homepage: http://code.opencv.org

#ifndef _GO_OPENCV_BINDING_H_
#define _GO_OPENCV_BINDING_H_

#include <cv.h> // include opencv version

// opencv version helper
#ifndef CV_MAKE_VERSION
#define CV_MAKE_VERSION(a,b,c) (((a) << 16) | ((b) << 8) | (c))
#endif
#ifndef CV_VERSION_NUM
#define CV_VERSION_NUM CV_MAKE_VERSION(CV_MAJOR_VERSION,CV_MINOR_VERSION,CV_SUBMINOR_VERSION)
#endif

// include opencv headers (must incude version only first!)
#if (CV_VERSION_NUM < CV_MAKE_VERSION(2,0,0))   // opencv 1.x
#   include <highgui.h>
#elif (CV_VERSION_NUM < CV_MAKE_VERSION(2,4,0)) // opencv 2.0/2.1/2.2/2.3
#   include <highgui.h>
#   include <opencv2/photo/photo_c.h>
#   include <opencv2/imgproc/imgproc_c.h>
#else
#   include <highgui.h>
#   include <opencv2/photo/photo_c.h>
#   include <opencv2/imgproc/imgproc_c.h>
#endif

// Trackbar
int GoOpenCV_CreateTrackbar(
	char* trackbar_name, char* window_name,
	int value, int count
);
void GoOpenCV_DestroyTrackbar(
	char* trackbar_name, char* window_name
);

// mouse callback
void GoOpenCV_SetMouseCallback(
	const char* window_name
);

// video writer args
unsigned GoOpenCV_FOURCC_(
	int c1, int c2, int c3, int c4
);

#endif // _GO_OPENCV_BINDING_H_


