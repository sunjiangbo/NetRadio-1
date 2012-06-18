/******************************************************************************
* Copyright (c) 2012, Letion
* All rights reserved.
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the University of California, Berkeley nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/
///============================================================================
/// \file    : VideoRenderer.h
/// \brief   : 视频Render类头文件
/// \author  : letion
/// \version : 1.0
/// \date    : 2012-06-18
///============================================================================
#ifndef __VIDEO_RENDERER_H__
#define __VIDEO_RENDERER_H__

#include "dshow\\streams.h"
#include "ICaptureEvent.h"

//=============================================================================
class CVideoRenderer : public CBaseRenderer
{
public:
	CVideoRenderer(LPUNKNOWN lpunk, HRESULT *phr);
	virtual ~CVideoRenderer(void);

public:
	virtual HRESULT DoRenderSample(IMediaSample *pMediaSample);
	virtual HRESULT CheckMediaType(const CMediaType *);
	CMediaType* GetMediaType();

public:
	/// 设置回调接口
	void SetCaptureEvent(ICaptureEvent* pCaptureEvent);

private:
	CMediaType  m_MediaType;			///< 媒体类型
	ICaptureEvent* m_pCaptureEvent;		///< 回调接口指针
};

#endif //__VIDEO_RENDERER_H__
