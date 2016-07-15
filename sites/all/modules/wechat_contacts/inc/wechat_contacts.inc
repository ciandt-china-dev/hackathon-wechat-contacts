<?php
function wechat_contacts_callback(){
  $we_obj = _wechat_contacts_init_obj();
  $we_obj->valid();
  $type = $we_obj->getRev()->getRevType();
  $request_data = $we_obj->getRevData();

watchdog('request_data', '<pre>$i</pre>', array('$i' => print_r($request_data, TRUE)), WATCHDOG_ERROR);
  $request_message = wechat_build_request_message($request_data);
watchdog('request_message', '<pre>$i</pre>', array('$i' => print_r($request_message, TRUE)), WATCHDOG_ERROR);
  $response_message = wechat_build_response_message($request_message);
watchdog('response_message', '<pre>$i</pre>', array('$i' => print_r($response_message, TRUE)), WATCHDOG_ERROR);
  $response_message->send();

}
function wechat_contacts_my_contacts(){
  $access_token_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=wx2ef8799c2a79ecae&corpsecret=JuB2C5V7U1jytolYZHorPxzW-U1VSIy3x4sgFFF_OuqYx-KI5jP-F2YoYgsQW06l");
  $access_token_object = json_decode($access_token_object);
  $access_token = $access_token_object->access_token;
  $code = $_GET['code'];
  $user_info_object = file_get_contents("https://qyapi.weixin.qq.com/cgi-bin/user/getuserinfo?access_token=".$access_token."&code=".$code);
  $user_info_object = json_decode($user_info_object);
  print_r($user_info_object);
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