var mConfig = {};

Pebble.addEventListener("ready", function(e) {
	//console.log("91 Dub v2.0 is ready");
  loadLocalData();
  returnConfigToPebble();
});

Pebble.addEventListener("showConfiguration", function(e) {
	Pebble.openURL(mConfig.configureUrl);
});

Pebble.addEventListener("webviewclosed",
  function(e) {
    if (e.response) {
      var config = JSON.parse(e.response);
      saveLocalData(config);
      returnConfigToPebble();
    }
  }
);

function saveLocalData(config) {

  //console.log("loadLocalData() " + JSON.stringify(config));

  localStorage.setItem("blink", parseInt(config.blink));  
  localStorage.setItem("invert", parseInt(config.invert)); 
  localStorage.setItem("bluetoothvibe", parseInt(config.bluetoothvibe)); 
  localStorage.setItem("hourlyvibe", parseInt(config.hourlyvibe)); 
  localStorage.setItem("branding_mask", parseInt(config.branding_mask)); 
	localStorage.setItem("battery_hide", parseInt(config.battery_hide)); 
	localStorage.setItem("seconds", parseInt(config.seconds)); 
	
  
  loadLocalData();

}
function loadLocalData() {
  
	mConfig.blink = parseInt(localStorage.getItem("blink"));
	mConfig.invert = parseInt(localStorage.getItem("invert"));
	mConfig.bluetoothvibe = parseInt(localStorage.getItem("bluetoothvibe"));
	mConfig.hourlyvibe = parseInt(localStorage.getItem("hourlyvibe"));
	mConfig.branding_mask = parseInt(localStorage.getItem("branding_mask"));
	mConfig.battery_hide = parseInt(localStorage.getItem("battery_hide"));
	mConfig.seconds = parseInt(localStorage.getItem("seconds"));
	
	mConfig.configureUrl = "http://www.mirz.com/91dubv2/index5.html";
	
	if(isNaN(mConfig.blink)) {
		mConfig.blink = 1;
	}
	if(isNaN(mConfig.invert)) {
		mConfig.invert = 0;
	}
	if(isNaN(mConfig.bluetoothvibe)) {
		mConfig.bluetoothvibe = 1;
	}
	if(isNaN(mConfig.hourlyvibe)) {
		mConfig.hourlyvibe = 0;
	}   
	if(isNaN(mConfig.branding_mask)) {
		mConfig.branding_mask = 0;
	}   
	if(isNaN(mConfig.battery_hide)) {
		mConfig.battery_hide = 0;
	}   
	if(isNaN(mConfig.seconds)) {
		mConfig.seconds = 0;
	}   

  //console.log("loadLocalData() " + JSON.stringify(mConfig));
}
function returnConfigToPebble() {
  //console.log("Configuration window returned: " + JSON.stringify(mConfig));
  Pebble.sendAppMessage({
    "blink":parseInt(mConfig.blink), 
    "invert":parseInt(mConfig.invert), 
    "bluetoothvibe":parseInt(mConfig.bluetoothvibe), 
    "hourlyvibe":parseInt(mConfig.hourlyvibe),
    "branding_mask":parseInt(mConfig.branding_mask),
    "battery_hide":parseInt(mConfig.battery_hide),
    "seconds":parseInt(mConfig.seconds)
  });    
}