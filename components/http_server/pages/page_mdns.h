/* mDNS page templates */

#define MDNS_CHUNK_FORM "\
<div style='display: flex; justify-content: space-between; align-items: center; margin-bottom: 0.5rem;'>\
<div style='display: flex; align-items: center;'>\
<a href='/' style='display: inline-block; margin-right: 1rem;'><img src='/favicon.png' alt='Home' style='width: 64px; height: 64px; border: none;'></a>\
<h1 style='margin: 0;'>mDNS Settings</h1>\
</div>\
</div>\
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
</div>"
