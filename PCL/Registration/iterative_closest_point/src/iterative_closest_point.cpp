// http://pointclouds.org/documentation/tutorials/iterative_closest_point.php

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

using namespace std;

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);
    
    // Fill the cloud data in
    cloud_in->width = 5;
    cloud_in->height = 1;
    cloud_in->is_dense = false;
    cloud_in->points.resize(cloud_in->width * cloud_in->height);
    
    for(size_t i = 0; i < cloud_in->points.size(); ++i)
    {
        cloud_in->points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
        cloud_in->points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
        cloud_in->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
    }
    
    cout << "Saved " << cloud_in->points.size() << " data points to input:" << endl;
    
    for(size_t i = 0; i < cloud_in->points.size(); ++i)
        cout << "    " << cloud_in->points[i].x << " " << cloud_in->points[i].y << " " << cloud_in->points[i].z << endl;
    
    *cloud_out = *cloud_in;    
    cout << "\nsize: " << cloud_out->points.size() << endl;
    
    for(size_t i = 0; i < cloud_in->points.size(); ++i)
        cloud_out->points[i].x = cloud_in->points[i].x + 0.7f;
    
    cout << "\nTransformed " << cloud_in->points.size() << " data points:" << endl;
    
    for(size_t i = 0; i < cloud_out->points.size(); ++i)
        cout << "    " << cloud_out->points[i].x << " " << cloud_out->points[i].y << " " << cloud_out->points[i].z << endl;
    
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    //icp.setInputCloud(cloud_in);
    icp.setInputSource(cloud_in);
    icp.setInputTarget(cloud_out);
    
    pcl::PointCloud<pcl::PointXYZ> Final;
    icp.align(Final);
    
    cout << "\nhas converged: " << icp.hasConverged() << " score: " << icp.getFitnessScore() << endl;
    cout << icp.getFinalTransformation() << endl;
    
    return(0);
}
