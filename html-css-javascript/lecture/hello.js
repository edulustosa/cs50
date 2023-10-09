const form = document.querySelector("form");
const input = document.querySelector("input");
const body = document.querySelector("body");

form.addEventListener("submit", (e) => {
  e.preventDefault();

  let name = input.value;
  const p = document.createElement("p");
  p.innerText = `hello, ${name}`;
  body.appendChild(p);
  input.value = "";
});
