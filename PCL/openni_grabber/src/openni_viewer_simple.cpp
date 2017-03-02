// http://pointclouds.org/documentation/tutorials/openni_grabber.php

#include <pcl/io/openni2_grabber.h>
#include <pcl/visualization/cloud_viewer.h>

using namespace std;

class SimpleOpenNIViewer
{
    public:
        SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}

        void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
        {
            if (!viewer.wasStopped())
                viewer.showCloud (cloud);
        }

        void run ()
        {
            pcl::Grabber* interface = new pcl::io::OpenNI2Grabber("#1");

            boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f = boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);

            interface->registerCallback (f);

            interface->start ();
            
            pcl::io::OpenNI2Grabber* grabber2 = dynamic_cast<pcl::io::OpenNI2Grabber*>(interface);
            boost::shared_ptr<pcl::io::openni2::OpenNI2Device> device = grabber2->getDevice();
            
            cout << "Device Name: " << device->getName() << " Uri: " << device->getUri() << " Has Color: " << device->hasColorSensor() << " Is Sinchronized: " << device->isSynchronized() << endl;

            while (!viewer.wasStopped())
            {
                boost::this_thread::sleep (boost::posix_time::seconds (1));
            }

            interface->stop ();
        }

        pcl::visualization::CloudViewer viewer;
};

int main ()
{
    SimpleOpenNIViewer v;
    v.run ();
    return 0;
}
