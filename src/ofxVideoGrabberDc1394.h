#ifndef _OFX_VIDEO_GRABBER_DC1394
#define _OFX_VIDEO_GRABBER_DC1394

#include "ofConstants.h"
#include "ofTexture.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofUtils.h"

#include <stdint.h>
#include <dc1394/dc1394.h>
#include <inttypes.h>



class ofxVideoGrabberPtgrey : public ofBaseVideo {

	public :

		ofxVideoGrabberPtgrey();
		virtual ~ofxVideoGrabberPtgrey();

		void 			listDevices();
		bool 			isFrameNew();
		void			grabFrame();
		void			close();
		bool			initGrabber(int w, int h, bool bTexture=true);
		void			videoSettings();
		unsigned char 	* getPixels();
		ofTexture &		getTextureReference();
		void 			setVerbose(bool bTalkToMe);
		void			setDeviceID(int _deviceID);
		void 			setUseTexture(bool bUse);
		void 			draw(float x, float y, float w, float h);
		void 			draw(float x, float y);
		void			update();

		//the anchor is the point the image is drawn around. 
		//this can be useful if you want to rotate an image around a particular point. 
        void			setAnchorPercent(float xPct, float yPct);	//set the anchor as a percentage of the image width/height ( 0.0-1.0 range )
        void			setAnchorPoint(int x, int y);				//set the anchor point in pixels
        void			resetAnchor();								//resets the anchor to (0, 0)

		float 			getHeight();
		float 			getWidth();

		int			height;
		int			width;
        
		//--------------------------------- libdc1394
		void setBrightness( int value);
		int getBrightness();
		void setExposure( int value);
		int getExposure();
		void setShutter( int value);
		int getShutter();
	
	protected:
                
		bool					bChooseDevice;
		//int					deviceID;
		uint64_t				deviceID;
		bool					bUseTexture;
		ofTexture 				tex;
		bool 					bVerbose;
		bool 					bGrabberInited;
	    unsigned char * 		pixels;
		bool 					bIsFrameNew;
        
		//--------------------------------- libdc1394
		dc1394camera_t*       camera;
		dc1394featureset_t    features;
		dc1394framerates_t    framerates;
		dc1394video_modes_t   video_modes;
		dc1394framerate_t     framerate;
		dc1394video_mode_t    video_mode;
		dc1394video_frame_t*  frame;
		dc1394_t*             driver;
		dc1394camera_list_t*  deviceList;
		dc1394error_t         err;
        
};




#endif

