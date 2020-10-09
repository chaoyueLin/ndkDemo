package com.example.ndksodemo;

import android.app.Application;
import android.os.Environment;


import java.io.File;


/*****************************************************************
 * * File: - FileUtils
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/10/9
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/10/9    1.0         create
 ******************************************************************/
public class FileUtils {
    private static final String FILE_PATH_PREFIX = APP.mContext.getExternalCacheDir() + File.separator;
    private static final String FOLDER_NAME = "NdkSample" + File.separator;
    public static final String FILE_PATH = FILE_PATH_PREFIX + FOLDER_NAME;


}