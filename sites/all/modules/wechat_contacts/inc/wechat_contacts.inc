<?php
function wechat_contacts_callback(){
  watchdog('error', $_GET["echostr"]);
  $we_obj = _wechat_contacts_init_obj();
  $we_obj->valid();
  $type = $we_obj->getRev()->getRevType();
  $request_data = $we_obj->getRevData();
  watchdog('wechat', $request_data);
  //$request_message = wechat_build_request_message($request_data);
  //watchdog('wechat', '123456'); 
  //$response_message = wechat_build_response_message($request_message);
  //$response_message->send();
}
function wechat_contacts_my_contacts(){
  $access_token_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=wx2ef8799c2a79ecae&corpsecret=JuB2C5V7U1jytolYZHorPxzW-U1VSIy3x4sgFFF_OuqYx-KI5jP-F2YoYgsQW06l");
  $access_token = $access_token_object->access_token;
  $code = $_GET['code'];
  $user_info = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/user/getuserinfo?access_token=".$access_token."&code=".$code);
  print_r($user_info);
}

function _wechat_contacts_init_obj() {
  $we_obj = &drupal_static(__FUNCTION__);
  if (!isset($we_obj)) {
    module_load_include('php', 'wechat_contacts', 'sdk/qywechat.class');
    $options = array(
      'token' => variable_get('wechat_token', "hackathon"),
      'appid' => variable_get('wechat_appid', "wx2ef8799c2a79ecae"),
      'appsecret' => variable_get('wechat_appsecret', "JuB2C5V7U1jytolYZHorPxzW-U1VSIy3x4sgFFF_OuqYx-KI5jP-F2YoYgsQW06l"),
      'encodingaeskey' => '1pj2XNHL8mj8xqTQmLJafQ2Yl4tV1NPTIFXFc3MwFA2',
      
    );
    $we_obj = new Wechat($options);
  }
  return $we_obj;
}