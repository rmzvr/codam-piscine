#!/bin/bash

id -nG $FT_USER | sed 's/ /,/g'
