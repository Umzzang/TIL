function onGeoOk(position) {
  console.log(position)
}
function onGeoError() {
  alert("can't find you.")
}

navigator.geolocation.getCurrentPosition(onGeoOk, onGeoError)