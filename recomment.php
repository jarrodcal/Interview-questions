<?php
    
    /* Remove comments from a program*/

    $handle = @fopen("redis-2.6.17/src/intset.c", 'r');

    if (!$handle)
    {
        echo "Open file error\n";
        exit;
    }

    while (($v = fgetc($handle)) !== false)
        delcomment($v, $handle);

    fclose($handle);

    function delcomment($v1, $handle)
    {
        if ($v1 == '/')
        {
            $v2 = fgetc($handle);

            if ($v2 == '*')
            {
                delmulitLine($handle);
            }
            else if ($v2 == '/')
            {
                fgets($handle);
            }
            else
            {
                echo $v1 . $v2;
            }
        }
        else
        {
            echo $v1;
        }
    }

    function delmulitLine($handle)
    {
        $c1 = fgetc($handle);
        $c2 = fgetc($handle);

        while (($c1 != '*') || ($c2 != '/'))
        {
            $c1 = $c2;
            $c2 = fgetc($handle);
        }
    }
