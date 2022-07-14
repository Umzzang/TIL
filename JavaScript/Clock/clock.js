
const clock = document.getElementById("clock")
const wantDate = document.getElementById("d")

let check = 0

function setDate (event) {
  const wishDate = event.target.valueAsDate
  const nowDate = new Date()
  let difDay = wishDate - nowDate
  const day = parseInt(difDay/(1000 * 60 * 60 * 24))
  difDay = difDay % (1000 * 60 * 60 * 24)
  const hour = parseInt(difDay/(1000 * 60 * 60))
  difDay = difDay % (1000 * 60 * 60)
  const minute = parseInt(difDay/(1000 * 60 ))
  difDay = difDay % (1000 * 60 )
  const second = parseInt(difDay/(1000 ))
  difDay = difDay % (1000 )
  
  clock.innerText = `${day}d ${hour}h ${minute}m ${second}s`
  check = 1
}



wantDate.addEventListener("change", setDate)

function setDate2 () {
  if (check === 1) {

    const wishDate = wantDate.valueAsDate
    const nowDate = new Date()
    let difDay = wishDate - nowDate
    const day = parseInt(difDay/(1000 * 60 * 60 * 24))
    difDay = difDay % (1000 * 60 * 60 * 24)
    const hour = parseInt(difDay/(1000 * 60 * 60))
    difDay = difDay % (1000 * 60 * 60)
    const minute = parseInt(difDay/(1000 * 60 ))
    difDay = difDay % (1000 * 60 )
    const second = parseInt(difDay/(1000 ))
    difDay = difDay % (1000 )
    
    clock.innerText = `${day}d ${hour}h ${minute}m ${second}s`
}
  
}


setInterval(setDate2, 500)


