/*
	Copyright (C) 2008, kobake

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such,
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/
#ifndef SAKURA_CSEARCHAGENT_FC5366A0_91D4_438B_80C6_DDA9791B50009_H_
#define SAKURA_CSEARCHAGENT_FC5366A0_91D4_438B_80C6_DDA9791B50009_H_

#include "global.h"

class CDocLineMgr;
struct DocLineReplaceArg;

class CSearchAgent{
public:
	// �����񌟍�
	static const wchar_t* SearchString(
		const wchar_t*	pLine,
		int				nLineLen,
		int				nIdxPos,
		const wchar_t*	pszPattern,
		int				nPatternLen,
		int*			pnCharCharsArr,
		bool			bLoHiCase
	);
	
	// ���������̏��
	static void CreateCharCharsArr(
		const wchar_t*	pszPattern,
		int				nSrcLen,
		int**			ppnCharCharsArr
	);

public:
	CSearchAgent(CDocLineMgr* pcDocLineMgr) : m_pcDocLineMgr(pcDocLineMgr) { }

	bool WhereCurrentWord( CLogicInt , CLogicInt , CLogicInt* , CLogicInt*, CNativeW*, CNativeW* );	/* ���݈ʒu�̒P��͈̔͂𒲂ׂ� */

	bool PrevOrNextWord( CLogicInt , CLogicInt , CLogicInt* , BOOL bLEFT, BOOL bStopsBothEnds );	/* ���݈ʒu�̍��E�̒P��̐擪�ʒu�𒲂ׂ� */
	//	Jun. 26, 2001 genta	���K�\�����C�u�����̍����ւ�
	int SearchWord( CLogicPoint ptSerachBegin, const wchar_t* , ESearchDirection eDirection, const SSearchOption& sSearchOption , CLogicRange* pMatchRange, CBregexp* ); /* �P�ꌟ�� */

	void ReplaceData( DocLineReplaceArg* );
private:
	CDocLineMgr* m_pcDocLineMgr;
};

#endif /* SAKURA_CSEARCHAGENT_FC5366A0_91D4_438B_80C6_DDA9791B50009_H_ */
/*[EOF]*/