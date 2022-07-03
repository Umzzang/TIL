import {useEffect, useState} from "react"

function App() {
  const [loading, setLoading] = useState(true)
  const [coins, setCoins] = useState([])
  const [money, setMoney] = useState(0)
  const [choosedCoin, setChoosedCoin] = useState(1)
  const changeCoin = (event) => {
    setChoosedCoin(event.target.value)
    
  }
  const onChange = (event) => {
    setMoney(event.target.value)
  }
  useEffect(() => {
    fetch("https://api.coinpaprika.com/v1/tickers")
    .then((res) => res.json())
    .then((json) => {
      setCoins(json)
      setLoading(false)
      setChoosedCoin(json[0].quotes.USD.price)
      
    })

  }, [])

  return (
    <div>
      <h1>The Coins! ({coins.length})</h1>
      {loading ? <strong>Loading...</strong>:null}
      <input onChange={onChange} value={money} text="number"></input>
      <br/>
      <select onChange={changeCoin}>
        {coins.map((coin, index) => (
          <option key={index} value={coin.quotes.USD.price}>
            {coin.name} ({coin.symbol}): {coin.quotes.USD.price}
          </option>
        ))}
      </select>
      <h3>{money/choosedCoin}</h3>
      <ul>
        {coins.map((coin, index) => 
        <li key={index}>
          {coin.name} ({coin.symbol}): {coin.quotes.USD.price}
        </li>
        )}
      </ul>
    </div>
  );
}

export default App;
