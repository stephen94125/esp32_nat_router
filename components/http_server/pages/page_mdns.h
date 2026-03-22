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
#container { max-width: 600px; margin: 0 auto; padding: 1.5rem; background: rgba(30, 30, 46, 0.9); border-radius: 16px; box-shadow: 0 8px 32px rgba(0, 0, 0, 0.4); backdrop-filter: blur(10px); }\
table { width: 100%; border-collapse: collapse; }\
td { padding: 0.5rem 0; vertical-align: top; }\
td:first-child { color: #888; font-size: 0.9rem; padding-right: 0.75rem; width: 35%; text-align: right; }\
.data-table { width: 100%; border-collapse: collapse; margin: 1rem 0; background: rgba(22, 33, 62, 0.6); border-radius: 12px; overflow: hidden; border: 1px solid rgba(0, 217, 255, 0.1); }\
.data-table thead { background: rgba(0, 217, 255, 0.1); }\
.data-table th { padding: 0.75rem 0.5rem; text-align: left; font-weight: 600; color: #00d9ff; font-size: 0.9rem; }\
.data-table td { padding: 0.75rem 0.5rem; border-bottom: 1px solid rgba(255, 255, 255, 0.05); font-size: 0.9rem; }\
.data-table td:first-child { color: #e0e0e0; text-align: left; width: auto; }\
.data-table tbody tr:last-child td { border-bottom: none; }\
.data-table tbody tr:hover { background: rgba(0, 217, 255, 0.05); }\
input[type='text'], input[type='number'], select { width: 100%; background: rgba(22, 33, 62, 0.6); border: 1px solid rgba(0, 217, 255, 0.2); border-radius: 8px; color: #e0e0e0; padding: 0.75rem; font-size: 0.95rem; }\
input:focus, select:focus { outline: none; border-color: #00d9ff; box-shadow: 0 0 0 3px rgba(0, 217, 255, 0.1); background: rgba(22, 33, 62, 0.8); }\
input::placeholder { color: #666; }\
select { cursor: pointer; -webkit-appearance: none; -moz-appearance: none; appearance: none; }\
input[type='checkbox'] { -webkit-appearance: none; -moz-appearance: none; appearance: none; width: 18px; height: 18px; border: 2px solid rgba(0, 217, 255, 0.3); border-radius: 4px; background: rgba(22, 33, 62, 0.6); cursor: pointer; vertical-align: middle; position: relative; flex-shrink: 0; }\
input[type='checkbox']:checked { background: #00d9ff; border-color: #00d9ff; }\
input[type='checkbox']:checked::after { content: ''; position: absolute; left: 4px; top: 1px; width: 6px; height: 10px; border: solid #1a1a2e; border-width: 0 2px 2px 0; transform: rotate(45deg); }\
input[type='checkbox']:focus { outline: none; border-color: #00d9ff; box-shadow: 0 0 0 3px rgba(0, 217, 255, 0.1); }\
.ok-button { border: none; border-radius: 8px; padding: 0.75rem 1.5rem; font-size: 0.95rem; font-weight: 600; cursor: pointer; width: 100%; margin-top: 0.5rem; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: #fff; box-shadow: 0 4px 15px rgba(102, 126, 234, 0.4); transition: transform 0.2s; }\
.ok-button:hover { transform: translateY(-2px); }\
.red-button { background: linear-gradient(135deg, #f093fb 0%, #f5576c 100%); color: #fff; border: none; border-radius: 6px; padding: 0.4rem 0.8rem; font-size: 0.8rem; font-weight: 600; cursor: pointer; transition: all 0.3s; box-shadow: 0 2px 8px rgba(245, 87, 108, 0.4); text-decoration: none; display: inline-block; }\
.red-button:hover { transform: translateY(-1px); box-shadow: 0 4px 12px rgba(245, 87, 108, 0.6); }\
.section { margin-bottom: 2rem; }\
small { display: block; color: #888; font-size: 0.85rem; margin-top: 0.5rem; line-height: 1.4; }\
@media (max-width: 600px) { body { padding: 0.5rem; } #container { padding: 1rem; } h1 { font-size: 1.25rem; } h2 { font-size: 1rem; } td:first-child { font-size: 0.8rem; width: 40%; } input[type='text'], input[type='number'], select { font-size: 0.9rem; padding: 0.65rem; } .ok-button { font-size: 0.9rem; padding: 0.65rem 1.25rem; } }\
.modal-overlay { display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0,0,0,0.7); z-index: 1000; justify-content: center; align-items: center; }\
.modal-overlay.show { display: flex; }\
.modal-box { background: rgba(30, 30, 46, 0.98); border: 2px solid #f5576c; border-radius: 12px; padding: 1.5rem; max-width: 400px; text-align: center; box-shadow: 0 8px 32px rgba(245, 87, 108, 0.3); }\
.modal-box h3 { color: #f5576c; margin-bottom: 1rem; }\
.modal-box p { color: #e0e0e0; margin-bottom: 1.5rem; }\
.modal-box button { background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: #fff; border: none; border-radius: 8px; padding: 0.75rem 2rem; font-size: 1rem; cursor: pointer; }\
</style>\
</head>\
<body>"

#define MDNS_CHUNK_MID1 "\
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

/* Uses: %s (enable), %s (host), %s (instance), %s (ap), %s (sta) */
#define MDNS_CHUNK_MID2 "\
<div class='section'>\
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
</form>\
</div>\
<div class='section'>\
<h2>mDNS Aliases</h2>\
<table class='data-table'>\
<thead>\
<tr>\
<th>Alias Name</th>\
<th>Action</th>\
</tr>\
</thead>\
<tbody>"

#define MDNS_CHUNK_MID3 "\
</tbody>\
</table>\
<form action='' method='GET'>\
<table>\
<tr><td>New Alias</td><td><input type='text' name='add_alias' placeholder='mqtt'/></td></tr>\
<tr><td></td><td><input type='submit' value='Add Alias' class='ok-button' style='margin-top: 0;'/></td></tr>\
</table>\
<small>.local domain appended automatically.</small>\
</form>\
</div>\
<div class='section'>\
<h2>Custom Services</h2>\
<table class='data-table'>\
<thead>\
<tr>\
<th>Service Type</th>\
<th>Port</th>\
<th>Action</th>\
</tr>\
</thead>\
<tbody>"


#define MDNS_CHUNK_TAIL "\
</tbody>\
</table>\
<form action='' method='GET'>\
<table>\
<tr><td>Service Type</td><td>\
<select name='add_svc_type'>\
<option value='_mqtt._tcp'>_mqtt._tcp (MQTT)</option>\
<option value='_http._tcp'>_http._tcp (Web Server)</option>\
<option value='_smb._tcp'>_smb._tcp (Samba/File Share)</option>\
<option value='_ssh._tcp'>_ssh._tcp (SSH)</option>\
<option value='_ftp._tcp'>_ftp._tcp (FTP)</option>\
<option value='_homeassistant._tcp'>_homeassistant._tcp</option>\
<option value='_printer._tcp'>_printer._tcp (LPR)</option>\
<option value='custom'>-- Custom --</option>\
</select>\
<input type='text' name='add_svc_custom' placeholder='_custom._tcp' style='margin-top:0.5rem; display:none;' id='custom_svc_input'/>\
</td></tr>\
<tr><td>Port</td><td><input type='number' name='add_svc_port' min='1' max='65535' placeholder='1883'/></td></tr>\
<tr><td></td><td><input type='submit' value='Add Service' class='ok-button' style='margin-top: 0;'/></td></tr>\
</table>\
</form>\
</div>\
<script>\
document.querySelector('select[name=\"add_svc_type\"]').addEventListener('change', function(e) {\
document.getElementById('custom_svc_input').style.display = e.target.value === 'custom' ? 'block' : 'none';\
});\
</script>\
<div style='margin-top: 2rem; text-align: center;'>\
<a href='/' style='padding: 0.75rem 2rem; background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%); color: #fff; border: none; border-radius: 8px; text-decoration: none; font-size: 0.95rem; font-weight: 600;'>🏠 Home</a>\
</div>\
</div>\
</body>\
</html>"
