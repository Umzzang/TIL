const toDoForm = document.getElementById("todo-form")
const toDoInput = toDoForm.querySelector("input")
const toDoList = document.getElementById("todo-list")
const TODOS_KEY = "todos"


let toDos = []


function saveToDos () {
  localStorage.setItem(TODOS_KEY, JSON.stringify(toDos))
}

function deleteToDo (event) { 
  const li = event.target.parentElement
  toDos = toDos.filter(todo => todo.id !== parseInt(li.id))
  saveToDos()

  li.remove()
}


function paintToDo (newTodo) {
  const li = document.createElement("li")
  li.id = newTodo.id
  const span = document.createElement("span")
  span.innerText = newTodo.text
  const button = document.createElement("button")
  button.innerText = "X"
  button.addEventListener("click", deleteToDo)
  li.appendChild(span)
  li.appendChild(button)
  toDoList.appendChild(li)

}


function handleToDoSubmit (event) {
  event.preventDefault()
  const newTodo = toDoInput.value
  toDoInput.value = '' 
  const newTodoObj = {
    text : newTodo,
    id : Date.now(),
  }
  toDos.push(newTodoObj)
  paintToDo(newTodoObj)
  saveToDos()
}

toDoForm.addEventListener("submit", handleToDoSubmit)

const savedTodos = localStorage.getItem(TODOS_KEY)

function sayHello(item) {
  console.log(`!! ${item}`)
}

if (savedTodos) {
  const parsedToDos = JSON.parse(savedTodos)
  toDos = parsedToDos
  parsedToDos.forEach(paintToDo);
}