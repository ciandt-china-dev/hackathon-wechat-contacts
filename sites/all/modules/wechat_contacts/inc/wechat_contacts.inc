<?php

function wechat_contacts_my_contacts(){
  $access_token_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=wx2ef8799c2a79ecae&corpsecret=JuB2C5V7U1jytolYZHorPxzW-U1VSIy3x4sgFFF_OuqYx-KI5jP-F2YoYgsQW06l");
  $access_token_object = json_decode($access_token_object);
  $access_token = $access_token_object->access_token;
  $code = $_GET['code'];
  $user_info_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/user/getuserinfo?access_token=".$access_token."&code=".$code);
  $user_info_object = json_decode($user_info_object);
  print_r($user_info_object);
}

