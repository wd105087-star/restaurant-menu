
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
    <title>雄中115的會沅制餐廳</title>
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+TC:wght@400;500;700&display=swap" rel="stylesheet">
    <style>
        body { 
            font-family: 'Noto Sans TC', Arial, sans-serif; 
            margin: 0; 
            padding: 20px; 
            background: linear-gradient(135deg, #fff6e5 0%, #fff0db 100%);
            min-height: 100vh;
        }
        .header { 
            display: flex; 
            justify-content: space-between; 
            align-items: center;
            padding: 12px 20px;
            background: white;
            border-radius: 12px;
            box-shadow: 0 2px 12px rgba(255, 87, 34, 0.1);
            margin-bottom: 24px;
        }
        h1 { 
            margin: 0; 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            -webkit-background-clip: text;
            background-clip: text;
            -webkit-text-fill-color: transparent;
            font-size: 1.8rem;
            font-weight: 700;
        }
        .cart-button { 
            position: relative; 
            padding: 10px 18px;
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: #fff;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .cart-button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }
        .cart-count { 
            position: absolute;
            top: -8px;
            right: -8px;
            background: #4caf50;
            color: #fff;
            border-radius: 50%;
            padding: 3px 7px;
            font-size: 12px;
            box-shadow: 0 2px 6px rgba(255,68,68,0.4);
        }

        .categories { 
            display: grid; 
            grid-template-columns: repeat(auto-fit, minmax(240px, 1fr)); 
            gap: 20px; 
            margin-top: 24px;
            padding: 0 10px;
        }
        .category-card { 
            background: white; 
            border-radius: 16px; 
            padding: 24px; 
            text-align: center; 
            box-shadow: 0 4px 20px rgba(0,0,0,0.06); 
            cursor: pointer;
            transition: transform 0.3s, box-shadow 0.3s;
            position: relative;
            overflow: hidden;
        }
        .category-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 8px 30px rgba(0,0,0,0.1);
        }
        .category-card h2 { 
            margin: 12px 0 0 0;
            color: #ff5722;
            font-weight: 600;
        }
        .category-card.active {
            background: #fff5f2;
            border: 2px solid #ff5722;
        }

        /* 商品列表 */
        #itemsContainer { 
            margin-top: 20px; 
            display: grid; 
            grid-template-columns: repeat(auto-fill, minmax(200px,1fr)); 
            gap: 16px;
            opacity: 0;
            transform: translateY(20px);
            transition: opacity 0.3s, transform 0.3s;
        }
        #itemsContainer.show {
            opacity: 1;
            transform: translateY(0);
        }
        .item-card { 
            background: white; 
            padding: 16px; 
            border-radius: 12px; 
            box-shadow: 0 4px 16px rgba(0,0,0,0.06);
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 6px 24px rgba(0,0,0,0.1);
        }
        .item-card h3 { 
            margin: 0 0 8px 0; 
            font-size: 17px;
            color: #e65100;
        }
        .item-card p { 
            margin: 0 0 12px 0; 
            color: #ff5722;
            font-weight: 500;
        }
        .item-card button { 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }

        /* 購物車彈窗 */
        .modal { 
            display: none; 
            position: fixed; 
            inset: 0; 
            background: rgba(0,0,0,0.6); 
            align-items: center; 
            justify-content: center;
            backdrop-filter: blur(4px);
        }
        .modal.open { 
            display: flex;
            animation: modalFadeIn 0.3s ease-out;
        }
        @keyframes modalFadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .modal-content { 
            background: white; 
            width: 90%; 
            max-width: 520px; 
            border-radius: 16px; 
            padding: 24px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.2);
        }
        .cart-item { 
            display: flex; 
            justify-content: space-between; 
            padding: 12px 0; 
            border-bottom: 1px solid #eee;
            align-items: center;
        }
        .cart-total { 
            text-align: right; 
            margin-top: 16px; 
            font-weight: bold;
            color: #e65100;
            font-size: 1.2em;
        }
        .close { 
            float: right; 
            cursor: pointer; 
            font-size: 24px;
            color: #666;
            transition: color 0.2s;
        }
        .close:hover {
            color: #ff5722;
        }
    </style>
</head>
<body>
    <div class="header">
        <h1>雄中115的會沅制餐廳</h1>
        <button class="cart-button" onclick="openCart()">購物車 <span class="cart-count">0</span></button>
    </div>

    <div class="categories" aria-label="主要分類">
        <div class="category-card" onclick="showCategoryItems('主食')"><div style="font-size:36px">🍜</div><h2>主食</h2></div>
        <div class="category-card" onclick="showCategoryItems('小菜')"><div style="font-size:36px">🥬</div><h2>小菜</h2></div>
        <div class="category-card" onclick="showCategoryItems('飲料')"><div style="font-size:36px">🥤</div><h2>飲料</h2></div>
        <div class="category-card" onclick="showCategoryItems('甜點')"><div style="font-size:36px">🍮</div><h2>甜點</h2></div>
    </div>

    <div id="itemsContainer" aria-live="polite"></div>

    <div id="orderControls" style="margin-top:24px; display:flex; gap:12px; align-items:center; background:white; padding:16px; border-radius:12px; box-shadow: 0 2px 12px rgba(255,87,34,0.1);">
        <label for="customerName" style="font-weight:500; color:#e65100;">訂購人姓名：</label>
        <input id="customerName" type="text" placeholder="請輸入姓名" style="padding:8px 12px; border-radius:8px; border:1px solid #e0e0e0; background:#f8f9ff; font-size:15px;">
        <button id="submitOrderBtn" onclick="submitOrder()" style="background:linear-gradient(45deg, #ff5722, #ff7043); color:white; border:none; padding:8px 16px; border-radius:8px; cursor:pointer; font-weight:500; transition:all 0.2s">送出訂單</button>
    </div>

    <div id="orderHistory" style="margin-top:16px"></div> 

    <div id="cartModal" class="modal" role="dialog" aria-modal="true">
        <div class="modal-content">
            <span class="close" onclick="closeCart()">&times;</span>
            <h2>購物車</h2>
            <div id="cartItems"></div>
            <div id="cartTotal" class="cart-total"></div>
        </div>
    </div>

    <script>
        // *** 您的 Apps Script URL 已整合於此 ***
        const GOOGLE_SHEETS_URL = 'https://script.google.com/macros/s/AKfycbxEE9Nu-_Ma0AG5awAawXJneZBh-oFo_n6jblQSF1dXnKjYCNMuFqDzNDB0-MGOgDPw/exec'; 

        const menuData = {
            主食: [ { name:'招牌沅味炒麵', price:120 }, { name:'章魚小丸子', price:80 } ],
            小菜: [ { name:'花生一級棒', price:45 } ],
            飲料: [ { name:'甜心紅茶', price:35 }, { name:'特製迎賓酒', price:60 } ],
            甜點: [ { name:'經典雪花布丁', price:40 } ]
        };

        let cart = [];

        function updateCartCount() {
            const count = cart.reduce((s, it) => s + it.quantity, 0);
            document.querySelector('.cart-count').textContent = count;
        }

        function openCart() {
            document.getElementById('cartModal').classList.add('open');
            renderCart();
        }
        function closeCart() { document.getElementById('cartModal').classList.remove('open'); }

        function addToCart(name, price, qty = 1) {
            qty = Number(qty) || 1;
            const found = cart.find(i => i.name === name && i.price === price);
            if (found) found.quantity += qty; else cart.push({ name, price, quantity: qty });
            updateCartCount();
        }

        function changeQty(idx, delta) {
            if (!cart[idx]) return;
            cart[idx].quantity += delta;
            if (cart[idx].quantity <= 0) cart.splice(idx,1);
            renderCart();
        }

        function removeFromCart(index) {
            cart.splice(index,1);
            renderCart();
        }

        function renderCart() {
            const container = document.getElementById('cartItems');
            container.innerHTML = '';
            let total = 0;
            if (cart.length === 0) container.innerHTML = '<p>購物車是空的。</p>';
            cart.forEach((it, idx) => {
                const div = document.createElement('div');
                div.className = 'cart-item';
                const subtotal = it.price * it.quantity;
                total += subtotal;
                div.innerHTML = `
                    <div style="font-weight:500">${it.name} × ${it.quantity}</div>
                    <div style="display:flex; align-items:center; gap:8px">
                        <span style="color:#ff5722; font-weight:500">NT$${subtotal}</span>
                        <button onclick="changeQty(${idx}, -1)" style="padding:4px 8px; border:none; background:#f5f5f5; border-radius:4px; cursor:pointer; color:#666">－</button>
                        <button onclick="changeQty(${idx}, 1)" style="padding:4px 8px; border:none; background:#f5f5f5; border-radius:4px; cursor:pointer; color:#666">＋</button>
                        <button onclick="removeFromCart(${idx})" style="padding:4px 8px; border:none; background:#ffebee; border-radius:4px; cursor:pointer; color:#ff5722">刪除</button>
                    </div>`;
                container.appendChild(div);
            });
            document.getElementById('cartTotal').textContent = '總計：NT$' + total;
            updateCartCount();
        }


        let currentCategory = null;
        const defaultCategory = '主食'; 

        // 已修復的顯示商品邏輯
        function showCategoryItems(cat) {
            const container = document.getElementById('itemsContainer');
            const cards = document.querySelectorAll('.category-card');
            const items = menuData[cat] || [];

            // 1. 處理收起邏輯：如果點擊的是當前分類，則收起
            if (currentCategory === cat) {
                container.classList.remove('show');
                cards.forEach(card => card.classList.remove('active'));
                currentCategory = null;
                setTimeout(() => {
                    if (!currentCategory) container.innerHTML = '';
                }, 300);
                return;
            }

            // 2. 處理顯示邏輯：
            container.classList.remove('show'); 
            container.innerHTML = ''; 
            
            currentCategory = cat;
            cards.forEach(card => {
                const isCurrentCategory = card.querySelector('h2').textContent === cat;
                card.classList.toggle('active', isCurrentCategory);
            });

            if (items.length === 0) { 
                container.innerHTML = '<p style="text-align:center;color:#666;padding:20px;">尚無商品</p>';
                container.classList.add('show'); 
                return; 
            }

            // 3. 延遲更新內容並顯示
            setTimeout(() => {
                container.innerHTML = items.map(it => `
                    <div class="item-card">
                        <h3>${it.name}</h3>
                        <p>NT$${it.price}</p>
                        <div style="display:flex; gap:8px; align-items:center; margin-top:12px">
                            <input class="item-qty" type="number" min="1" value="1" style="width:64px; padding:8px; border-radius:8px; border:1px solid #e0e0e0; background:#f8f9ff;">
                            <button onclick="(function(btn){ const qty = parseInt(btn.parentElement.querySelector('.item-qty').value)||1; addToCart('${it.name}', ${it.price}, qty); })(this)">加入購物車</button>
                        </div>
                    </div>
                `).join('');
                container.classList.add('show'); 
            }, 50);
        }

        // 訂單處理邏輯 (傳送到 Google Sheets)
        function submitOrder() {
            const nameEl = document.getElementById('customerName');
            const name = nameEl.value.trim();
            
            if (!name) { alert('請填寫訂購人姓名'); nameEl.focus(); return; }
            if (cart.length === 0) { alert('購物車為空，請先加入商品'); return; }
            
            const total = cart.reduce((s, it) => s + it.price * it.quantity, 0);

            if (!confirm(`確認送出訂單\n訂購人：${name}\n訂單總金額：NT$${total}\n\n注意：訂單將自動傳送到 Google 試算表。`)) return;
            
            // 準備訂單資料為 JSON 格式
            const orderData = {
                customer: name,
                total: total,
                items: cart.map(it => ({ name: it.name, price: it.price, quantity: it.quantity }))
            };
            
            // 透過 fetch 將 JSON 資料 POST 給 Google Apps Script
            fetch(GOOGLE_SHEETS_URL, {
                method: 'POST',
                mode: 'no-cors', 
                cache: 'no-cache',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify(orderData)
            })
            .then(response => {
                // 清空購物車和表單
                cart = [];
                document.getElementById('customerName').value = '';
                updateCartCount();
                renderCart();
                closeCart();
                
                alert('✅ 訂單送出成功！請稍後在您的 Google 試算表中查看紀錄。');
            })
            .catch(error => {
                console.error('Error submitting order:', error);
                alert('❌ 訂單送出失敗！請檢查您的 Apps Script 部署狀態。');
            });
        }

        function renderOrderHistory() {
            const el = document.getElementById('orderHistory');
            el.innerHTML = ''; 
        }

        // 初始化
        updateCartCount();
        showCategoryItems(defaultCategory); 
        renderOrderHistory();
    </script>
</body>
</html>
        /* 商品列表 */
        #
](https://wd105087-star.github.io/restaurant-menu/)
