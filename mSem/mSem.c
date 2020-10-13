/***************************************************************************
*
* Copyright (c) 2020, Xinkerr
*
* This file is part of mSem.
*
* this is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* Disclaimer:
* AUTHOR MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* AUTHOR SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* LICENSE: LGPL V2.1
* see: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
*
* Create Date:   2020/10/14
* Modified Date: 2020/10/14
* Version:1.0
* Github: https://github.com/Xinkerr
* Mail: 634326056@qq.com
*
****************************************************************************/

#include <string.h>
#include "mSem.h"

/**
 * @brief 信号量初始化
 * 
 * @param[out] : 信号量
 * 
 * @retrun：M_SEM_OK,成功; M_SEM_FAIL, 出错
 */
mSem_err_t mSem_init(mSem_t* sem)
{
    if(sem != NULL)
    {
        *sem = 0;
        return M_SEM_OK;
    }
    else
        return M_SEM_FAIL;
}

/**
 * @brief 信号量释放(值+1)
 * 
 * @param[out] : 信号量
 * 
 * @retrun：M_SEM_OK,成功; M_SEM_FAIL, 出错
 */
mSem_err_t mSem_release(mSem_t* sem)
{
    mSem_err_t ret;
    if(sem != NULL)
    {
        if(*sem < 0xff)
        {
            (*sem)++;
            ret = M_SEM_OK;
        }
        else
        {
            ret = M_SEM_FAIL;
        }
    }
    else
        ret = M_SEM_FAIL;
    return ret;
}

/**
 * @brief 获取信号量(值-1)
 * 
 * @param[out] : 信号量
 * 
 * @retrun：M_SEM_OK,成功获取信号量; M_SEM_FAIL, 信号量出错或无信号量
 */
mSem_err_t mSem_take(mSem_t* sem)
{
    mSem_err_t ret;
    if(sem != NULL)
    {
        if(*sem > 0)
        {
            (*sem)--;
            ret = M_SEM_OK;
        }
        else
        {
            ret = M_SEM_FAIL;
        }
    }
    else
        ret = M_SEM_FAIL;
    return ret;
}