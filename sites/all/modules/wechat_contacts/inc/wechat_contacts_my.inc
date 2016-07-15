<?php
function wechat_contacts_my_info(){
  $we_obj = wechat_contacts_init_obj();
  $code = $_GET['code'];
  $user_info_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/user/getuserinfo?access_token=".$we_obj->token."&code=".$code);
  $user_info_object = json_decode($user_info_object);
  $UserId = $user_info_object->UserId;
  print_r($UserId);
}