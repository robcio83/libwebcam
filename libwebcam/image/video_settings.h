#pragma once

#include "format.h"
#ifndef WIN32
#include <linux/videodev2.h>
#else
#include <wmsdkidl.h>
#endif

namespace webcam
{

	enum Quality
	{
		Quality_Poor = 1,
		Quality_Medium = 15,
		Quality_Good = 50,
		Quality_Best = 95,
	};

	enum FPS
	{
		FPS_VerySlow = 1,
		FPS_Slow = 6,
		FPS_Medium = 12,
		FPS_Fluent = 16,
		FPS_Default = FPS_Slow,
	};

	class resolution
	{
	public:
		static const short DEFAULT_WIDTH;
		static const short DEFAULT_HEIGHT;
		resolution(short width_ = DEFAULT_WIDTH, short height_ = DEFAULT_HEIGHT);
		bool operator < (const resolution & resolution_)const;
		bool operator != (const resolution & resolution_)const;
		short get_width()const;
		short get_height()const;

		void set_width(short width_);
		void set_height(short height_);
	protected:
		short _width;
		short _height;
	};

	class video_settings
	{
	public:
		video_settings();
		video_settings(const video_settings & video_settings_);
		~video_settings();

		const video_settings & operator=(const video_settings & video_settings_);

		const format & get_format()const;
		unsigned char get_fps()const;
		unsigned int get_height()const;
		unsigned char get_quality()const;
		const resolution & get_resolution()const;
		unsigned int get_width()const;

		void set_format(const format & format_);
		void set_fps(unsigned char fps_);
		void set_quality(unsigned char quality_);
		void set_resolution(const resolution & resolution_);
	protected:
		void free_format();
		void assign_from(const video_settings & video_settings_);
		format * _format;
		unsigned char _fps;
		unsigned char _quality;
		resolution _resolution;
	};

}
