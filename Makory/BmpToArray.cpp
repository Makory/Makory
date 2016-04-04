// BmpToArray.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "BmpToArray.h"


// BmpToArray

IMPLEMENT_DYNAMIC(BmpToArray, CWnd)

BmpToArray::BmpToArray()
{

}

BmpToArray::~BmpToArray()
{
}

void BmpToArray::LoadBmp(LPCTSTR lpszPathName){
		
	CFile infile;
	CFileException e;
	CString fileName;
	fileName.Format(lpszPathName);		//파일이름 문자열은 유니코드로해야함. 고정된 문자열이라면 L을 앞에 붙여줘야함 -> 유니코드에서 멀티코드사용으로 불가피하게 바꾸면서 문자열 앞에 L 쓸 필요 없어짐
	infile.Open(fileName,CFile::modeRead | CFile::typeBinary,&e);
	if(infile==NULL) {
		AfxMessageBox("NULL");						//정상적으로 파일이 들어갔는지 검사
		exit(1);
	}

	// BMP Header Information
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	infile.Read(&hf,sizeof(BITMAPFILEHEADER));		//dibHf에 파일헤더를 읽어들인다.
	infile.Read(&hInfo,sizeof(BITMAPINFOHEADER));	//영상정보의 header를 읽기

	if(hf.bfType!=0x4D42) {
		AfxMessageBox("Not BMP file!!");			//bmp인지 검사
		exit(1);
	}

	int ImgSize;
	if(hInfo.biBitCount!=24) {
		AfxMessageBox("Not 24bit");				//24bit인지 검사
		exit(1);
	}else { 
		ImgSize = hInfo.biSizeImage;				//이미지 사이즈
	}

	unsigned char *m_InImg;							//BGR 이미지가 들어갈 배열
	m_InImg=new unsigned char [ImgSize];
	infile.Read(m_InImg, ImgSize);
	
	unsigned char *m_OutImg;							//RGB 이미지가 들어갈 배열
	m_OutImg=new unsigned char [ImgSize];
	infile.Read(m_InImg, ImgSize);
	for(int i=0; i<ImgSize; i++) {
		m_OutImg[i]=m_InImg[ImgSize-i];
	}
	for(int i=0; i<ImgSize; i++) {
		m_InImg[i]=m_OutImg[i];
	}

	delete (m_OutImg);
	//infile.Close();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, hInfo.biWidth, hInfo.biHeight, 0, GL_RGB,
        GL_UNSIGNED_BYTE, m_InImg);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,  GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
}


BEGIN_MESSAGE_MAP(BmpToArray, CWnd)
END_MESSAGE_MAP()



// BmpToArray 메시지 처리기입니다.


