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
/// \file    : ConfigFile.h
/// \brief   : �����ļ���ͷ�ļ�
/// \author  : letion
/// \version : 1.0
/// \date    : 2012-05-17
///============================================================================

#ifndef __CONFIG_FILE_H__
#define __CONFIG_FILE_H__

#include "IConfigFile.h"
#include "ConfigFileBase.h"
#include "ConfigFileIni.h"
#include "ConfigFileXml.h"
#include "CriticalSection.h"

//=============================================================================
class CConfigFile : public IConfigFile
{
public:
	CConfigFile(void);
	~CConfigFile(void);

public:
	/// ��
	virtual BOOL OpenFile(const char* szPathName, 
		ENUM_CONFIG_FILE_TYPE enFileType = CONFIG_FILE_INI);
	/// �ر�
	virtual BOOL CloseFile(void);
	/// ����
	virtual BOOL SaveFile(void);

public:
	/// �������
	virtual const char* GetValueString(const char* szSection, 
		const char* szKey, const char* szDefaultValue);

	/// ��������
	virtual BOOL SetValueString(const char* szSection, 
		const char* szKey, const char* szValue);

	/// �������
	virtual int32_t GetValueInt(const char* szSection, 
		const char* szKey, int32_t nDefaultValue);

	/// ��������
	virtual BOOL SetValueInt(const char* szSection, 
		const char* szKey, int32_t nValue);

	/// �������
	virtual double GetValueDouble(const char* szSection, 
		const char* szKey, double nDefaultValue);

	/// ��������
	virtual BOOL SetValueDouble(const char* szSection, 
		const char* szKey, double nValue);

private:
	CConfigFileBase* m_pConfigFile;			///< �����ļ���ָ��
	CCriticalSection m_oConfigLock;			///< �����ļ��ٽ�
};

#endif //__CONFIG_FILE_H__