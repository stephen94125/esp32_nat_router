/* mDNS page templates */

#define MDNS_CHUNK_HEAD "<html>\
<head>\
<meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0'>\
<meta charset='UTF-8'>\
<title>mDNS Settings</title>\
<link rel='icon' href='favicon.png'>\
<style>\
* { box-sizing: border-box; margin: 0; padding: 0; }\
body { font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif; background: linear-gradient(135deg, #1a1a2e 0%, #16213e 100%); color: #e0e0e0; padding: 1rem; min-height: 100vh; line-height: 1.6; }\
h1 { font-size: 1.5rem; font-weight: 600; color: #00d9ff; margin-bottom: 1rem; text-shadow: 0 0 20px rgba(0, 217, 255, 0.3); }\
h2 { font-size: 1.15rem; font-weight: 500; color: #00d9ff; margin: 1.5rem 0 0.75rem 0; padding-bottom: 0.5rem; border-bottom: 1px solid rgba(0, 217, 255, 0.2); }\
#container { max-width: 500px; margin: 0 auto; padding: 1.5rem; background: rgba(30, 30, 46, 0.9); border-radius: 16px; box-shadow: 0 8px 32px rgba(0, 0, 0, 0.4); backdrop-filter: blur(10px); }\
table { width: 100%; border-collapse: collapse; }\
td { padding: 0.5rem 0; vertical-align: top; }\
td:first-child { color: #888; font-size: 0.9rem; padding-right: 0.75rem; width: 35%; text-align: right; }\
input[type='text'], input[type='password'], input[type='number'] { width: 100%; background: rgba(22, 33, 62, 0.6); border: 1px solid rgba(0, 217, 255, 0.2); border-radius: 8px; color: #e0e0e0; padding: 0.75rem; font-size: 0.95rem; }\
input[type='text']:focus, input[type='password']:focus, input[type='number']:focus { outline: none; border-color: #00d9ff; box-shadow: 0 0 0 3px rgba(0, 217, 255, 0.1); background: rgba(22, 33, 62, 0.8); }\
input::placeholder { color: #666; }\
input[type='checkbox'], input[type='radio'] { -webkit-appearance: none; -moz-appearance: none; appearance: none; width: 18px; height: 18px; border: 2px solid rgba(0, 217, 255, 0.3); border-radius: 4px; background: rgba(22, 33, 62, 0.6); cursor: pointer; vertical-align: middle; position: relative; flex-shrink: 0; }\
input[type='checkbox']:checked, input[type='radio']:checked { background: #00d9ff; border-color: #00d9ff; }\
input[type='checkbox']:checked::after { content: ''; position: absolute; left: 4px; top: 1px; width: 6px; height: 10px; border: solid #1a1a2e; border-width: 0 2px 2px 0; transform: rotate(45deg); }\
input[type='checkbox']:focus, input[type='radio']:focus { outline: none; border-color: #00d9ff; box-shadow: 0 0 0 3px rgba(0, 217, 255, 0.1); }\
.ok-button { border: none; border-radius: 8px; padding: 0.75rem 1.5rem; font-size: 0.95rem; font-weight: 600; cursor: pointer; width: 100%; margin-top: 0.5rem; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: #fff; box-shadow: 0 4px 15px rgba(102, 126, 234, 0.4); transition: transform 0.2s; }\
.ok-button:hover { transform: translateY(-2px); }\
small { display: block; color: #888; font-size: 0.85rem; margin-top: 0.5rem; line-height: 1.4; }\
@media (max-width: 600px) { body { padding: 0.5rem; } #container { padding: 1rem; } h1 { font-size: 1.25rem; } h2 { font-size: 1rem; } td:first-child { font-size: 0.8rem; width: 40%; } input[type='text'], input[type='password'], input[type='number'] { font-size: 0.9rem; padding: 0.65rem; } .ok-button { font-size: 0.9rem; padding: 0.65rem 1.25rem; } }\
</style>\
</head>\
<body>\
<div id='container'>\
<div style='display: flex; justify-content: space-between; align-items: center; margin-bottom: 0.5rem;'>\
<div style='display: flex; align-items: center;'>\
<a href='/' style='display: inline-block; margin-right: 1rem;'><img src='/favicon.png' alt='Home' style='width: 64px; height: 64px; border: none;'></a>\
<h1 style='margin: 0;'>mDNS Settings</h1>\
</div>"

#define MDNS_CHUNK_SCRIPT "\
</div>\
<script>\
if (window.location.search.indexOf('reset=1') !== -1) {\
document.getElementById('container').style.display = 'none';\
document.body.innerHTML ='<div id=\"container\"><h1>mDNS Settings</h1><p style=\"text-align:center; margin: 2rem 0; color: #00d9ff;\">Settings saved! Rebooting...</p></div>';\
setTimeout(\"location.href = '/'\", 10000);\
}\
</script>"

#define MDNS_CHUNK_FORM "\
<h2>mDNS Configuration</h2>\
<form action='' method='GET'>\
<input type='hidden' name='mdns_save' value='1'/>\
<table>\
<tr><td>Service</td><td>\
<label><input type='checkbox' name='mdns_en' value='1' %s> Enable mDNS</label>\
</td></tr>\
<tr><td>Hostname</td><td><input type='text' name='mdns_host' value='%s' placeholder='nat-router'/></td></tr>\
<tr><td>Instance Name</td><td><input type='text' name='mdns_inst' value='%s' placeholder='ESP32 Camper Router'/></td></tr>\
<tr><td>Bind Interfaces</td><td>\
<label style='margin-right: 0.8rem;'><input type='checkbox' name='mdns_ap' value='1' %s> Bind to AP</label>\
<label style='margin-right: 0.8rem;'><input type='checkbox' name='mdns_sta' value='1' %s> Bind to STA</label>\
</td></tr>\
<tr><td></td><td><input type='submit' value='Save &amp; Reboot' class='ok-button'/></td></tr>\
</table>\
<small>.local domain will be appended to Hostname automatically.</small>\
</form>\
<div style='margin-top: 2rem; text-align: center;'>\
<a href='/' style='padding: 0.75rem 2rem; background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%); color: #fff; border: none; border-radius: 8px; text-decoration: none; font-size: 0.95rem; font-weight: 600;'>🏠 Home</a>\
</div>\
</div>\
</body>\
</html>"
