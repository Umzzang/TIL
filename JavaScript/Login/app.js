const numberInput = document.getElementById("maxNum");

function setMaxNum() {
  const maxNum = numberInput.value ? numberInput.value : "";
  console.log(maxNum)
}

numberInput.addEventListener("change", setMaxNum);

const yourInput = document.getElementById("yourNum");

function setYourNum() {
  const yourNum = yourInput.value ? yourInput.value : 0;
}

yourInput.addEventListener("change", setYourNum);


function play () {
  const result = document.getElementById("result")
  result.innerText = `You chose: ${yourNum}, the machine chose: `
  
}
const btn = document.getElementById("play")
btn.addEventListener("click", play)
