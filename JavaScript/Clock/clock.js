
const clock = document.getElementById("clock")

function setClock () {
  const date = new Date()
  const day = String(date.getDate().padStart(3,"0"))
  const hour = String(date.getHours().padStart(2,"0"))
  const minute = String(date.getMinutes().padStart(2,"0"))
  const second = String(date.getSeconds().padStart(2,"0"))
  clock.innerText = `${day}d ${hour}h ${minute}m ${second}s`
}

setClock()
setInterval(setClock, 500)