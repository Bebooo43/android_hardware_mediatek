/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#include "fmr.h"

#ifdef __cplusplus
extern "C" {
#endif

int MT6627_open_dev(const char *pname, int *fd)
{
	int ret = 0;
	ret =  COM_open_dev(pname, fd);

	//TODO important!!!, check if it's valid FM chip here.

	return ret;
}

/*int MT6627_stop_scan(int fd)
{
	int ret = 0;
	if (fd < 0){
        LOGE("FM fd unavailable for stopscan\n");
		ret = ERR_INVALID_FD;
        goto out;
    }
    
    if(lseek(fd, 0, SEEK_END) != 0){
    	LOGE("Stopscan failed\n");
		ret = -1;
        goto out;
    }else
        LOGD("Stopscan Success,[fd=%d]\n", fd);
out:
	return ret;   
}*/

void MT6627_init(struct fm_cbk_tbl *cbk_tbl)
{
    //Basic functions.
    cbk_tbl->open_dev = MT6627_open_dev;
    cbk_tbl->close_dev = COM_close_dev;
    cbk_tbl->pwr_up = COM_pwr_up;
    cbk_tbl->pwr_down = COM_pwr_down;
    cbk_tbl->tune = COM_tune;
    cbk_tbl->set_mute = COM_set_mute;
    cbk_tbl->is_rdsrx_support = COM_is_rdsrx_support;
    cbk_tbl->turn_on_off_rds = COM_turn_on_off_rds;
    cbk_tbl->get_chip_id = COM_get_chip_id;
    //For RDS RX.
    cbk_tbl->read_rds_data = COM_read_rds_data;
    cbk_tbl->get_ps = COM_get_ps;
    cbk_tbl->get_rt = COM_get_rt;
    cbk_tbl->active_af = COM_active_af;
    //FM short antenna
    cbk_tbl->ana_switch = COM_ana_switch;
    cbk_tbl->desense_check = COM_desense_check;
    //soft mute tune
    cbk_tbl->soft_mute_tune = COM_Soft_Mute_Tune;
    cbk_tbl->pre_search = COM_pre_search;
    cbk_tbl->restore_search = COM_restore_search;
  	return;
}

#ifdef __cplusplus
}
#endif

