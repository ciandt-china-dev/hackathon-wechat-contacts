<?php
function wechat_contacts_callback(){
  $we_obj = _wechat_contacts_init_obj();
  $we_obj->valid();
  //$type = $we_obj->getRev()->getRevType();
  //$request_data = $we_obj->getRevData();
  //watchdog('wechat', '123');
  //$request_message = wechat_build_request_message($request_data);
  //watchdog('wechat', '123456'); 
  //$response_message = wechat_build_response_message($request_message);
  //$response_message->send();
}

function _wechat_contacts_init_obj() {
  $we_obj = &drupal_static(__FUNCTION__);
  if (!isset($we_obj)) {
    module_load_include('php', 'wechat_contacts', 'sdk/qywechat.class');
    $options = array(
      'token' => variable_get('wechat_token', "hackathon"),
      'appid' => variable_get('wechat_appid', "wx2ef8799c2a79ecae"),
      'appsecret' => variable_get('wechat_appsecret', "JuB2C5V7U1jytolYZHorPxzW-U1VSIy3x4sgFFF_OuqYx-KI5jP-F2YoYgsQW06l"),
    );
    $we_obj = new Wechat($options);
  }
  return $we_obj;
}