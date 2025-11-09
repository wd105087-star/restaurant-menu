
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
    <title>雄中115的會沅制餐廳</title>
    
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+TC:wght@400;500;700&display=swap" rel="stylesheet">
    <style>
        /* 由於篇幅限制，CSS 樣式在此處省略，確保其與功能邏輯無關 */
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
            text-decoration: none !important;
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
            border: none;
            outline: none;
            color: inherit;
            font-family: inherit;
            -webkit-tap-highlight-color: transparent;
            user-select: none;
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
            padding: calc(24px - 2px); 
        }

        #itemsContainer { 
            margin-top: 20px; 
            display: grid; 
            grid-template-columns: repeat(auto-fill, minmax(200px,1fr)); 
            gap: 16px;
            opacity: 0; 
            transform: translateY(20px); 
            transition: opacity 0.3s ease-out, transform 0.3s ease-out; 
            overflow: hidden;
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
            text-decoration: none !important;
        }
        .item-card button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }
        
        /* 新增的選項樣式 */
        .option-group {
            margin-bottom: 10px;
            padding: 5px 0;
            border-top: 1px dashed #f0f0f0;
            display: flex;
            flex-direction: column;
            gap: 5px;
        }
        .option-group.inline {
             flex-direction: row; 
             align-items: center; 
             justify-content: space-between;
             border-top: none; 
             padding-top: 0;
        }
        .option-group label {
            font-size: 14px;
            color: #555;
            font-weight: 400;
            margin: 0; 
        }
        select, input[type="checkbox"], input[type="text"] {
            border: 1px solid #ddd;
            border-radius: 4px;
            padding: 5px 10px;
            font-size: 15px;
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
            z-index: 1000; 
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
            max-height: 80vh; 
            overflow-y: auto; 
        }
        .cart-item { 
            display: flex; 
            flex-direction: column; 
            justify-content: space-between; 
            padding: 12px 0; 
            border-bottom: 1px solid #eee;
            align-items: flex-start; 
        }
        .cart-item-name {
            font-weight: 500;
            margin-bottom: 8px; 
            flex-grow: 1;
            width: 100%; 
            white-space: normal; 
            word-break: break-word; 
        }
        .cart-item-controls {
            display: flex; 
            align-items: center; 
            gap: 8px;
            width: 100%; 
            justify-content: space-between; 
        }
        .cart-item-qty-controls {
            display: flex;
            gap: 5px;
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

        /* 聯絡區塊樣式 */
        .contact-info-icon {
            margin-top: 40px;
            text-align: center; 
            padding: 20px 0;
        }
        .contact-info-icon p {
            font-size: 1rem;
            color: #555;
            margin-bottom: 15px;
        }
        .ig-icon-link {
            text-decoration: none;
            color: #833AB4; 
            display: inline-block;
            transition: transform 0.2s, color 0.2s;
        }
        .ig-icon-link i {
            font-size: 48px; 
        }
        .ig-icon-link:hover {
            color: #C135A2; 
            transform: scale(1.1); 
        }
        /* 針對禁用欄位的樣式 */
        input[readonly] {
            cursor: not-allowed;
            background-color: #f1f1f1 !important;
            color: #555;
        }

        /* 調整訂單控制區塊佈局以容納更多選單 */
        #orderControls {
            display: grid !important; 
            grid-template-columns: repeat(auto-fill, minmax(100px, 1fr)); /* 更靈活的佈局 */
            gap: 12px 10px !important;
            align-items: center;
            padding: 16px;
        }
        /* 讓選項組件佔據更多空間 */
        .order-control-group {
            display: contents; /* 讓子元素直接參與 grid 佈局 */
        }
        .order-control-group label {
            white-space: nowrap;
            font-weight: 500; 
            color: #e65100;
        }
        .order-control-group input[type="text"], 
        .order-control-group select,
        .order-control-group .radio-group {
            width: 100%; 
            box-sizing: border-box; 
            grid-column: span 1;
        }
        .radio-group {
            display: flex;
            gap: 10px;
            align-items: center;
        }
        .radio-group label {
            font-weight: normal; 
            color: #333;
            display: flex;
            align-items: center;
            gap: 5px;
        }

        /* 讓送出按鈕佔滿一行或兩欄 */
        #orderControls #submitOrderBtn {
            grid-column: 1 / -1; /* 佔滿整行 */
            width: 100%;
            margin-top: 10px;
        }

        /* 調整移動端佈局 */
        @media (min-width: 601px) {
            #orderControls {
                grid-template-columns: auto 1fr auto 1fr auto 1fr; 
            }
            .order-control-group:nth-child(1) { grid-column: 1 / 3; } /* 外送/自取佔兩欄 */
            .order-control-group:nth-child(2) { grid-column: 3 / 5; } /* 姓名佔兩欄 */
            .order-control-group:nth-child(3) { grid-column: 5 / 7; } /* 班級+座號 佔兩欄 */
            
            /* 將日期和時間排在第二行 */
            .order-control-group:nth-child(4) { grid-column: 1 / 3; } 
            .order-control-group:nth-child(5) { grid-column: 3 / 5; }
            .order-control-group:nth-child(6) { grid-column: 5 / 7; }
        }
        @media (max-width: 600px) {
             #orderControls {
                grid-template-columns: 1fr 1fr; 
            }
            .order-control-group, #orderControls #submitOrderBtn {
                grid-column: 1 / span 2 !important; /* 所有項目在小螢幕上都佔滿兩欄 */
            }
        }
    </style>
</head>
<body>
    <div class="header">
        <h1>雄中115的會沅制餐廳</h1>
        <button class="cart-button" onclick="openCart()">購物車 <span class="cart-count">0</span></button>
    </div>

    <div class="categories" aria-label="主要分類">
        <button class="category-card" type="button" onclick="showCategoryItems('主食')"><div style="font-size:36px">🍜</div><h2>主食</h2></button>
        <button class="category-card" type="button" onclick="showCategoryItems('飲料')"><div style="font-size:36px">🥤</div><h2>飲料</h2></button>
        <button class="category-card" type="button" onclick="showCategoryItems('甜點')"><div style="font-size:36px">🍮</div><h2>甜點</h2></button>
    </div>

    <div id="itemsContainer" aria-live="polite"></div>

    <div id="orderControls" style="margin-top:24px; background:white; padding:16px; border-radius:12px; box-shadow: 0 2px 12px rgba(255,87,34,0.1);">
        
        <div class="order-control-group">
            <label style="font-weight:700; color:#e65100;">取餐方式：</label>
            <div class="radio-group">
                <label>
                    <input type="radio" name="orderType" value="自取" checked>
                    自取
                </label>
                <label>
                    <input type="radio" name="orderType" value="外送">
                    外送
                </label>
            </div>
        </div>

        <div class="order-control-group">
            <label for="customerName">訂購人姓名：</label>
            <input id="customerName" type="text" placeholder="請輸入姓名">
        </div>
        
        <div class="order-control-group" style="display: flex; gap: 10px;">
            <div style="flex-grow: 1; min-width: 40%;">
                <label for="classSelect">班級：</label>
                <select id="classSelect"></select> </div>
            <div style="flex-grow: 1; min-width: 40%;">
                <label for="seatSelect">座號：</label>
                <select id="seatSelect"></select> </div>
        </div>
        
        <div class="order-control-group">
            <label for="pickupDate">取餐日期：</label>
            <input id="pickupDate" type="date" value="2025-11-15" readonly style="cursor: not-allowed; background:#f1f1f1;">
        </div>

        <div class="order-control-group">
            <label for="pickupTime">取餐時間：</label>
            <select id="pickupTime"></select>
        </div>
        
        <button id="submitOrderBtn" onclick="submitOrder()">送出訂單</button>
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
    
    <div class="contact-info-icon">
        <p>有問題請聯繫我們：</p>
        <a href="https://www.instagram.com/kshs_115/" target="_blank" class="ig-icon-link">
            <i class="fab fa-instagram"></i>
        </a>
    </div>

    <script>
        // 【⭐ 重要：請替換成您最新部署的 Apps Script 網址！】
        const GOOGLE_SHEETS_URL = 'https://script.google.com/macros/s/AKfycbxEE9Nu-_Ma0AG5awAawXJneZBh-oFo_n6jblQSF1dXnKjYCNMuFqDzNDB0-MGOgDPw/exec'; 

        // === 【所有菜單項目】 ===
        const menuData = {
            主食: [ 
                { name:'炒麵麵包 (原味)', price:50 }, 
                { name:'極霸炒麵（牛肉+蝦仁）', price:65 },
                { name:'超極霸炒麵 (肉量 max)', price:95 }
            ],
            飲料: [ 
                { name:'可樂', price:25 }, 
                { name:'芬達', price:25 },
                { name:'雪碧', price:25 }, 
                { name:'迎賓酒', price:25 },
                { name:'昏睡紅茶', price:25 }
            ],
            甜點: [ 
                { name:'手工布丁', price:45 } 
            ]
        };
        // ===================================

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
            cart.push({ name, price, quantity: qty });
            updateCartCount();
            alert('🛒 成功加入購物車！'); 
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
                    <div class="cart-item-name">
                        ${it.name} × ${it.quantity}
                    </div>
                    <div class="cart-item-controls">
                        <span style="color:#ff5722; font-weight:700">NT$${subtotal}</span>
                        <div class="cart-item-qty-controls">
                            <button onclick="changeQty(${idx}, -1)" style="padding:4px 8px; border:none; background:#f5f5f5; border-radius:4px; cursor:pointer; color:#666; font-size:14px">－</button>
                            <button onclick="changeQty(${idx}, 1)" style="padding:4px 8px; border:none; background:#f5f5f5; border-radius:4px; cursor:pointer; color:#666; font-size:14px">＋</button>
                            <button onclick="removeFromCart(${idx})" style="padding:4px 8px; border:none; background:#ffebee; border-radius:4px; cursor:pointer; color:#ff5722; font-size:14px">刪除</button>
                        </div>
                    </div>`;
                container.appendChild(div);
            });
            document.getElementById('cartTotal').textContent = '總計：NT$' + total;
            updateCartCount();
        }

        function generateTimeSlots() {
            const startTimeMin = 9 * 60 + 30; // 9:30
            const endTimeMin = 13 * 60 + 30; // 13:30
            const interval = 15;
            const select = document.getElementById('pickupTime');
            
            if (!select) {
                console.error('Error: pickupTime select element not found.');
                return;
            }

            select.innerHTML = ''; 
            
            for (let currentMin = startTimeMin; currentMin <= endTimeMin; currentMin += interval) {
                const hour = Math.floor(currentMin / 60);
                const minute = currentMin % 60;
                
                const timeStr = `${String(hour).padStart(2, '0')}:${String(minute).padStart(2, '0')}`;
                
                const option = document.createElement('option');
                option.value = timeStr;
                option.textContent = timeStr;
                select.appendChild(option);
            }
        }
        
        // ⭐ 新增：生成班級選單
        function generateClassSelect() {
            const select = document.getElementById('classSelect');
            if (!select) return;

            // 定義班級範圍
            const classes = [];
            for (let i = 101; i <= 128; i++) classes.push(String(i));
            for (let i = 201; i <= 228; i++) classes.push(String(i));
            for (let i = 301; i <= 328; i++) classes.push(String(i));

            select.innerHTML = '<option value="">請選擇班級</option>'; // 預設選項
            classes.forEach(cls => {
                const option = document.createElement('option');
                option.value = cls;
                option.textContent = cls;
                select.appendChild(option);
            });
        }

        // ⭐ 新增：生成座號選單
        function generateSeatSelect() {
            const select = document.getElementById('seatSelect');
            if (!select) return;

            select.innerHTML = '<option value="">請選擇座號</option>'; // 預設選項
            for (let i = 1; i <= 38; i++) {
                const option = document.createElement('option');
                option.value = String(i).padStart(2, '0'); // 保持兩位數字格式
                option.textContent = String(i);
                select.appendChild(option);
            }
        }


        let currentCategory = null;

        function showCategoryItems(cat) {
            const container = document.getElementById('itemsContainer');
            const cards = document.querySelectorAll('.category-card');
            const items = menuData[cat] || [];

            // 處理點擊同一分類卡片時收起選單的邏輯
            if (currentCategory === cat) {
                container.classList.remove('show');
                cards.forEach(card => card.classList.remove('active'));
                currentCategory = null;
                requestAnimationFrame(() => { container.innerHTML = ''; }); 
                return;
            }

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
            
            // 核心邏輯：生成商品卡片 HTML
            const itemsHtml = items.map((it, index) => {
                let optionsHtml = '';
                const itemID = `item-${cat}-${index}`; 
                
                if (cat === '主食') {
                    // 主食選項
                    optionsHtml = `
                        <div class="option-group">
                            <label for="${itemID}-flavor">選擇口味：</label>
                            <select id="${itemID}-flavor">
                                <option value="原味" selected>原味</option>
                                <option value="海苔">海苔</option>
                                <option value="沅味">沅味</option>
                            </select>
                        </div>
                        <div class="option-group inline">
                            <label for="${itemID}-egg" style="margin: 0;">加購糖心蛋 (+NT$15)</label>
                            <input type="checkbox" id="${itemID}-egg" data-price="15" style="width: auto;">
                        </div>
                    `;
                } else if (it.name === '昏睡紅茶') {
                    // 昏睡紅茶只保留鮮奶茶選項，價格 +10
                    optionsHtml = `
                        <div class="option-group inline">
                            <label for="${itemID}-milk" style="font-weight: 500; color: #ff5722;">升級鮮奶茶 (+NT$10)</label>
                            <input type="checkbox" id="${itemID}-milk" data-price="10" style="width: auto;">
                        </div>
                        <div style="height: 10px; border-top: 1px dashed #f0f0f0; margin-bottom: 15px;"></div>
                    `;
                } else {
                    // 其他普通商品 (其他飲料和甜點)
                    optionsHtml = `
                        <div style="height: 10px; border-top: 1px dashed #f0f0f0; margin-bottom: 15px;"></div>
                    `;
                }

                return `
                    <div class="item-card">
                        <h3>${it.name}</h3>
                        <p id="${itemID}-price-display">NT$${it.price}</p>
                        
                        ${optionsHtml} <div style="display:flex; gap:8px; align-items:center; margin-top:12px">
                            <input class="item-qty" type="number" min="1" value="1" style="width:64px; padding:8px; border-radius:8px; border:1px solid #e0e0e0; background:#f8f9ff;">
                            <button onclick="handleAddToCart(this, '${it.name}', ${it.price}, '${cat}', ${index})">加入購物車</button>
                        </div>
                    </div>
                `;
            }).join('');
            
            container.innerHTML = itemsHtml; // 將生成的 HTML 內容放入容器
            
            // 確保容器顯示
            requestAnimationFrame(() => {
                container.classList.add('show');
            });
        }
        
        function handleAddToCart(btn, baseName, basePrice, cat, index) {
            const qtyInput = btn.parentElement.querySelector('.item-qty');
            const qty = parseInt(qtyInput.value)||1; 
            
            let finalName = baseName;
            let finalPrice = basePrice;
            const itemID = `item-${cat}-${index}`;
            let optionsList = [];

            if (cat === '主食') {
                const flavor = document.getElementById(`${itemID}-flavor`).value;
                const eggCheckbox = document.getElementById(`${itemID}-egg`);
                
                optionsList.push(flavor);
                
                if (eggCheckbox.checked) {
                    finalPrice += parseInt(eggCheckbox.dataset.price); 
                    optionsList.push('+糖心蛋');
                }
                
                finalName = `${baseName} (${optionsList.join(', ')})`;

                document.getElementById(`${itemID}-flavor`).value = '原味';
                eggCheckbox.checked = false;

            } else if (baseName === '昏睡紅茶') {
                const milkCheckbox = document.getElementById(`${itemID}-milk`); 
                let baseType = '紅茶';

                if (milkCheckbox.checked) {
                    finalPrice += parseInt(milkCheckbox.dataset.price); 
                    baseType = '鮮奶茶';
                }
                optionsList.push(baseType);
                
                finalName = `${baseName} [${optionsList.join(' | ')}]`;
                milkCheckbox.checked = false;
            } else {
                finalName = baseName;
                finalPrice = basePrice;
            }
            
            addToCart(finalName, finalPrice, qty); 
            qtyInput.value = 1; 
        }

        // 訂單處理邏輯 (傳送到 Google Sheets)
        function submitOrder() {
            // 獲取所有新增加的資訊
            const orderType = document.querySelector('input[name="orderType"]:checked').value;
            const nameEl = document.getElementById('customerName');
            const className = document.getElementById('classSelect').value;
            const seatNumber = document.getElementById('seatSelect').value;
            
            const name = nameEl.value.trim();
            const pickupDate = document.getElementById('pickupDate').value; 
            const pickupTime = document.getElementById('pickupTime').value; 
            
            const fullPickupTime = pickupDate + ' ' + pickupTime; 
            
            if (!name) { alert('請填寫訂購人姓名'); nameEl.focus(); return; }
            if (!className) { alert('請選擇班級'); document.getElementById('classSelect').focus(); return; }
            if (!seatNumber) { alert('請選擇座號'); document.getElementById('seatSelect').focus(); return; }
            if (cart.length === 0) { alert('購物車為空，請先加入商品'); return; }
            
            const total = cart.reduce((s, it) => s + it.price * it.quantity, 0);
            const fullID = `${className}${seatNumber}`;

            if (!confirm(`確認送出訂單\n取餐方式: ${orderType}\n班級座號: ${fullID}\n訂購人: ${name}\n取餐時間: ${pickupDate} ${pickupTime}\n訂單總金額: NT$${total}`)) return;
            
            // 準備訂單資料為 JSON 格式 (包含新的欄位)
            const orderData = {
                orderType: orderType, // 新增欄位
                customerID: fullID, // 班級座號合併
                customer: name, 
                total: total, 
                items: cart.map(it => `${it.name} x${it.quantity} (NT$${it.price})`).join('\n'),
                pickupTime: fullPickupTime 
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
                document.getElementById('classSelect').value = '';
                document.getElementById('seatSelect').value = '';
                document.querySelector('input[name="orderType"][value="自取"]').checked = true; // 重設為自取

                updateCartCount();
                renderCart();
                closeCart();
                
                alert('✅ 訂單送出成功！');
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

        // 確保所有初始化函式正確執行
        document.addEventListener('DOMContentLoaded', () => {
             updateCartCount();
             generateTimeSlots(); 
             generateClassSelect(); // ⭐ 新增初始化
             generateSeatSelect(); // ⭐ 新增初始化
             renderOrderHistory();
        });
    </script>
</body>
</html>
